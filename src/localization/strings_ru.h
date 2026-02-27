#ifndef STRINGS_RU_H
#define STRINGS_RU_H

#include "LocalizationTypes.h"

namespace papyrix {

// Russian strings
constexpr LocalizedStrings STRINGS_RU = {
  // Home screen
  .home_no_book = "Книга не открыта",
  .home_press_files = "Нажмите \"Файлы\" для просмотра",
  
  // Button labels
  .btn_files = "Файлы",
  .btn_sync = "Синхр.",
  .btn_settings = "Настройки",
  .btn_read = "Читать",
  .btn_back = "Назад",
  .btn_select = "Выбрать",
  .btn_menu = "Меню",
  .btn_home = "Домой",
  
  // Menu titles
  .title_files = "Файлы",
  .title_chapters = "Главы",
  .title_settings = "Настройки",
  .title_cleanup = "Очистка",
  .title_system_info = "Информация",
  .title_reader = "Чтение",
  .title_device = "Устройство",
  .title_network = "Сеть",
  .title_calibre_sync = "Синхр. Calibre",
  
  // Settings menu items
  .settings_reader = "Чтение",
  .settings_device = "Устройство",
  .settings_cleanup = "Очистка",
  .settings_system_info = "Информация",
  
  // Reader menu items
  .reader_chapters = "Главы",
  .reader_settings = "Настройки",
  .reader_home = "Домой",
  
  // Reader settings
  .reader_theme = "Тема",
  .reader_font_size = "Размер шрифта",
  .reader_text_layout = "Макет текста",
  .reader_line_spacing = "Межстрочный интервал",
  .reader_text_aa = "Сглаживание текста",
  .reader_alignment = "Выравнивание",
  .reader_hyphenation = "Переносы",
  .reader_show_images = "Показывать изображения",
  .reader_status_bar = "Строка состояния",
  .reader_orientation = "Ориентация",
  
  // Font size values
  .font_size_xs = "Очень мелкий",
  .font_size_s = "Мелкий",
  .font_size_m = "Обычный",
  .font_size_l = "Крупный",
  
  // Text layout values
  .layout_compact = "Компактный",
  .layout_standard = "Стандартный",
  .layout_large = "Крупный",
  
  // Line spacing values
  .spacing_tight = "Узкий",
  .spacing_normal = "Обычный",
  .spacing_relaxed = "Свободный",
  .spacing_loose = "Широкий",
  
  // Alignment values
  .align_justified = "По ширине",
  .align_left = "По левому краю",
  .align_center = "По центру",
  .align_right = "По правому краю",
  
  // Status bar values
  .status_bar_off = "Выкл",
  .status_bar_minimal = "Минимальная",
  .status_bar_full = "Полная",
  
  // Orientation values
  .orient_portrait = "Портрет",
  .orient_landscape = "Альбом",
  .orient_portrait_inv = "Портрет (перевёрнутый)",
  .orient_landscape_inv = "Альбом (перевёрнутый)",
  
  // Device settings
  .device_sleep_timeout = "Таймаут сна",
  .device_sleep_screen = "Экран сна",
  .device_startup = "При запуске",
  .device_short_pwr = "Короткое нажатие питания",
  .device_pages_refresh = "Страниц до обновления",
  .device_sunlight_fix = "Исправление выцветания",
  .device_front_buttons = "Передние кнопки",
  .device_side_buttons = "Боковые кнопки",
  .device_language = "Язык",
  
  // Sleep timeout values
  .sleep_5min = "5 минут",
  .sleep_10min = "10 минут",
  .sleep_30min = "30 минут",
  .sleep_1hour = "1 час",
  .sleep_never = "Никогда",
  
  // Sleep screen values
  .sleep_screen_blank = "Пустой",
  .sleep_screen_logo = "Логотип",
  .sleep_screen_cover = "Обложка книги",
  .sleep_screen_last_page = "Последняя страница",
  
  // Startup values
  .startup_home = "Главный экран",
  .startup_last_book = "Последняя книга",
  
  // Short power button values
  .short_pwr_sleep = "Сон",
  .short_pwr_menu = "Меню",
  .short_pwr_nothing = "Ничего",
  
  // Pages refresh values
  .pages_refresh_1 = "Каждую страницу",
  .pages_refresh_3 = "Каждые 3 страницы",
  .pages_refresh_5 = "Каждые 5 страниц",
  .pages_refresh_10 = "Каждые 10 страниц",
  .pages_refresh_never = "Никогда",
  
  // Toggle values
  .toggle_on = "Вкл",
  .toggle_off = "Выкл",
  
  // Button mapping values
  .buttons_page_turn = "Перелистывание",
  .buttons_disabled = "Отключены",
  
  // Cleanup menu
  .cleanup_cache = "Очистить кэш страниц",
  .cleanup_thumbnails = "Очистить миниатюры",
  .cleanup_all = "Очистить всё",
  
  // System info labels
  .info_firmware = "Прошивка",
  .info_device = "Устройство",
  .info_free_heap = "Свободная память",
  .info_sd_card = "SD карта",
  .info_battery = "Батарея",
  .info_wifi_mac = "WiFi MAC",
  
  // Network
  .network_scanning = "Сканирование...",
  .network_connecting = "Подключение...",
  .network_connected = "Подключено",
  .network_failed = "Ошибка подключения",
  .network_no_networks = "Сети не найдены",
  
  // Calibre sync
  .calibre_connecting = "Подключение к Calibre...",
  .calibre_syncing = "Синхронизация книг...",
  .calibre_complete = "Синхронизация завершена",
  .calibre_error = "Ошибка синхронизации",
  
  // Messages
  .msg_loading = "Загрузка...",
  .msg_error = "Ошибка",
  .msg_success = "Успешно",
  .msg_processing = "Обработка...",
  .msg_please_wait = "Пожалуйста, подождите...",
  
  // File operations
  .file_opening = "Открытие файла...",
  .file_parsing = "Разбор...",
  .file_error = "Ошибка файла"
};

}  // namespace papyrix

#endif  // STRINGS_RU_H
