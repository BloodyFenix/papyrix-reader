# Localization Files

Эта папка содержит файлы локализации для Papyrix Reader.

## Структура файлов

```
localization/
├── README.md              # Этот файл
├── LocalizationTypes.h    # Определение типов и структур
├── strings_en.h           # Английские строки
├── strings_ru.h           # Русские строки
└── strings_XX.h           # Другие языки (добавляются по мере необходимости)
```

## Файлы

### LocalizationTypes.h

Содержит:
- `enum class Language` - перечисление поддерживаемых языков
- `struct LocalizedStrings` - структура со всеми переводимыми строками

Этот файл является общим для всех языков и определяет интерфейс локализации.

### strings_en.h

Английские переводы всех строк. Это язык по умолчанию.

### strings_ru.h

Русские переводы всех строк.

## Добавление нового языка

### Шаг 1: Создать файл переводов

Создайте новый файл `strings_XX.h` (где XX - код языка):

```cpp
#ifndef STRINGS_XX_H
#define STRINGS_XX_H

#include "LocalizationTypes.h"

namespace papyrix {

// Your language strings
constexpr LocalizedStrings STRINGS_XX = {
  .home_no_book = "Translation here",
  .home_press_files = "Translation here",
  // ... все остальные строки
};

}  // namespace papyrix

#endif  // STRINGS_XX_H
```

### Шаг 2: Добавить язык в LocalizationTypes.h

```cpp
enum class Language {
  English,
  Russian,
  YourLanguage  // Добавить здесь
};
```

### Шаг 3: Подключить в Localization.h

В файле `src/Localization.h`:

```cpp
#include "localization/strings_en.h"
#include "localization/strings_ru.h"
#include "localization/strings_XX.h"  // Добавить
```

### Шаг 4: Обновить Localization.cpp

В файле `src/Localization.cpp`:

```cpp
void Localization::setLanguage(Language lang) {
  currentLanguage_ = lang;
  
  switch (lang) {
    case Language::English:
      currentStrings_ = &STRINGS_EN;
      break;
    case Language::Russian:
      currentStrings_ = &STRINGS_RU;
      break;
    case Language::YourLanguage:  // Добавить
      currentStrings_ = &STRINGS_XX;
      break;
    default:
      currentStrings_ = &STRINGS_EN;
      break;
  }
}
```

### Шаг 5: Добавить в настройки UI

В файле `src/ui/views/SettingsViews.h`:

```cpp
static constexpr const char* const LANGUAGE_VALUES[] = {
  "English", 
  "Русский",
  "Your Language"  // Добавить
};
```

## Рекомендации по переводу

### 1. Используйте файл английского языка как шаблон

Скопируйте `strings_en.h` и замените все строки на ваш язык.

### 2. Сохраняйте структуру

Все поля должны быть заполнены. Не удаляйте и не добавляйте поля.

### 3. Проверяйте длину строк

Убедитесь, что переведенные строки помещаются в UI элементы.

### 4. Используйте UTF-8

Все файлы должны быть сохранены в кодировке UTF-8.

### 5. Тестируйте на устройстве

Проверьте, что все символы отображаются корректно на E-Ink дисплее.

## Категории строк

### Home screen (Главный экран)
Строки для главного экрана приложения.

### Button labels (Метки кнопок)
Короткие метки для кнопок навигации.

### Menu titles (Заголовки меню)
Заголовки различных экранов и меню.

### Settings (Настройки)
Названия настроек и их значений.

### Messages (Сообщения)
Системные сообщения, ошибки, статусы.

### Network & Sync (Сеть и синхронизация)
Сообщения, связанные с сетевыми операциями.

## Проверка полноты перевода

Убедитесь, что все поля структуры `LocalizedStrings` заполнены:

```bash
# Подсчет строк в английском файле
grep -c "^\s*\." strings_en.h

# Подсчет строк в вашем файле
grep -c "^\s*\." strings_XX.h

# Числа должны совпадать
```

## Тестирование

После добавления нового языка:

1. Соберите проект: `pio run`
2. Прошейте устройство: `pio run --target upload`
3. Откройте Settings → Device → Language
4. Выберите ваш язык
5. Проверьте все экраны на корректность перевода

## Поддержка

Если у вас есть вопросы или нужна помощь с переводом, создайте issue в репозитории проекта.

## Вклад в проект

Мы приветствуем переводы на новые языки! Если вы хотите добавить перевод:

1. Создайте файл `strings_XX.h` с переводом
2. Следуйте инструкциям выше для интеграции
3. Протестируйте на устройстве
4. Создайте Pull Request

Спасибо за вклад в проект! 🌍
