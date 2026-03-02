#!/usr/bin/env python3
"""
Конвертирует монохромный BMP файл в массив C для PapyrixLogo.h
"""

import sys
import struct
from pathlib import Path


def read_bmp_to_array(bmp_path):
    """Читает монохромный BMP и возвращает массив байтов для C"""
    
    with open(bmp_path, 'rb') as f:
        # Читаем BMP заголовок
        header = f.read(14)
        if header[0:2] != b'BM':
            raise ValueError("Не BMP файл")
        
        # Читаем DIB заголовок
        dib_header_size = struct.unpack('<I', f.read(4))[0]
        f.seek(14)  # Вернуться к началу DIB
        dib_header = f.read(dib_header_size)
        
        # Парсим размеры
        width = struct.unpack('<I', dib_header[4:8])[0]
        height = struct.unpack('<I', dib_header[8:12])[0]
        bpp = struct.unpack('<H', dib_header[14:16])[0]
        
        print(f"BMP: {width}x{height}, {bpp} bpp", file=sys.stderr)
        
        if bpp != 1:
            raise ValueError(f"Ожидается 1 bpp, получено {bpp} bpp")
        
        if width != 128 or height != 128:
            raise ValueError(f"Ожидается 128x128, получено {width}x{height}")
        
        # Получаем offset данных
        data_offset = struct.unpack('<I', header[10:14])[0]
        
        # Переходим к данным
        f.seek(data_offset)
        
        # BMP хранит строки снизу вверх, нужно перевернуть
        # Каждая строка выровнена по 4 байта
        row_bytes = (width + 7) // 8  # 128 / 8 = 16 байт
        row_padding = (4 - (row_bytes % 4)) % 4
        
        rows = []
        for _ in range(height):
            row_data = f.read(row_bytes)
            f.read(row_padding)  # Пропустить padding
            rows.append(row_data)
        
        # Переворачиваем строки (BMP хранит снизу вверх)
        rows.reverse()
        
        # Объединяем все строки
        pixel_data = b''.join(rows)
        
        return pixel_data


def format_c_array(data, bytes_per_line=19):
    """Форматирует байты как массив C"""
    lines = []
    for i in range(0, len(data), bytes_per_line):
        chunk = data[i:i+bytes_per_line]
        hex_values = ', '.join(f'0x{b:02X}' for b in chunk)
        lines.append(f'    {hex_values}{"," if i + bytes_per_line < len(data) else ""}')
    return '\n'.join(lines)


def main():
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <input.bmp> <output.h>", file=sys.stderr)
        sys.exit(1)
    
    input_path = Path(sys.argv[1])
    output_path = Path(sys.argv[2])
    
    if not input_path.exists():
        print(f"Ошибка: файл {input_path} не найден", file=sys.stderr)
        sys.exit(1)
    
    print(f"Конвертация {input_path} -> {output_path}", file=sys.stderr)
    
    # Читаем BMP
    pixel_data = read_bmp_to_array(input_path)
    
    print(f"Прочитано {len(pixel_data)} байт", file=sys.stderr)
    
    # Генерируем C код
    c_array = format_c_array(pixel_data)
    
    output_content = f"""#pragma once
#include <cstdint>

static const uint8_t PapyrixLogo[] = {{
{c_array}
}};
"""
    
    # Записываем файл
    output_path.write_text(output_content, encoding='utf-8')
    
    print(f"Готово! Создан {output_path}", file=sys.stderr)


if __name__ == '__main__':
    main()
