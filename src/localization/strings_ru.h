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
  .btn_settings = "Настр.",
  .btn_read = "Читать",
  .btn_back = "Назад",
  .btn_select = "Выбор",
  .btn_menu = "Меню",
  .btn_home = "Домой",
  .btn_open = "Открыть",
  .btn_run = "Запуск",
  .btn_confirm = "Подтв.",
  .btn_left = "<",
  .btn_right = ">",
  
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
  .title_sync = "Синхронизация",
  
  // Sync menu items
  .sync_file_transfer = "Передача файлов",
  .sync_calibre_wireless = "Calibre по WiFi",
  
  // Settings menu items
  .settings_reader = "Чтение",
  .settings_device = "Устройство",
  .settings_cleanup = "Очистка",
  .settings_system_info = "Информация",
  
  // Reader menu items
  .reader_menu = "Меню",
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
  .status_bar_none = "Нет",
  .status_bar_title = "Название",
  .status_bar_chapter = "Глава",
  
  // Orientation values
  .orient_portrait = "Портрет",
  .orient_landscape_cw = "Альбом ПЧС",
  .orient_inverted = "Перевёрнутый",
  .orient_landscape_ccw = "Альбом ПРЧС",
  
  // Device settings
  .device_sleep_timeout = "Таймаут сна",
  .device_sleep_screen = "Экран сна",
  .device_startup = "При запуске",
  .device_short_pwr = "Кнопка питания",
  .device_pages_refresh = "Обновление",
  .device_sunlight_fix = "Исправл. выцветания",
  .device_front_buttons = "Передние кнопки",
  .device_side_buttons = "Боковые кнопки",
  .device_language = "Язык",
  
  // Sleep timeout values
  .sleep_5min = "5 минут",
  .sleep_10min = "10 минут",
  .sleep_15min = "15 минут",
  .sleep_30min = "30 минут",
  .sleep_1hour = "1 час",
  .sleep_never = "Никогда",
  .sleep_sleeping = "СПЯЩИЙ РЕЖИМ",
  
  // Sleep screen values
  .sleep_screen_dark = "Тёмный",
  .sleep_screen_light = "Светлый",
  .sleep_screen_custom = "Свой",
  .sleep_screen_cover = "Обложка",
  .sleep_screen_blank = "Пустой",
  .sleep_screen_logo = "Логотип",
  .sleep_screen_last_page = "Последняя страница",
  
  // Startup values
  .startup_home = "Главный экран",
  .startup_last_book = "Последняя книга",
  
  // Short power button values
  .short_pwr_ignore = "Игнорировать",
  .short_pwr_sleep = "Сон",
  .short_pwr_page_turn = "Перелистывание",
  .short_pwr_menu = "Меню",
  .short_pwr_nothing = "Ничего",
  
  // Pages refresh values
  .pages_refresh_1 = "Каждую страницу",
  .pages_refresh_3 = "Каждые 3 страницы",
  .pages_refresh_5 = "Каждые 5 страниц",
  .pages_refresh_10 = "Каждые 10 страниц",
  .pages_refresh_15 = "Каждые 15 страниц",
  .pages_refresh_30 = "Каждые 30 страниц",
  .pages_refresh_never = "Никогда",
  
  // Toggle values
  .toggle_on = "Вкл",
  .toggle_off = "Выкл",
  
  // Button mapping values
  .buttons_page_turn = "Перелистывание",
  .buttons_disabled = "Отключены",
  
  // Cleanup menu
  .cleanup_book_cache = "Очистить кэш книг",
  .cleanup_device_storage = "Очистить память устройства",
  .cleanup_factory_reset = "Сброс до заводских",
  
  // System info labels
  .info_version = "Версия",
  .info_uptime = "Время работы",
  .info_battery = "Батарея",
  .info_chip = "Чип",
  .info_cpu = "Процессор",
  .info_free_memory = "Своб. память",
  .info_internal_disk = "Внутр. диск",
  .info_sd_card = "SD карта",
  .info_sd_ready = "Готова",
  .info_sd_not_available = "Недоступна",
  
  // Network
  .network_mode = "Режим сети",
  .network_mode_connect = "Подключиться к существующей WiFi",
  .network_mode_hotspot = "Создать точку доступа WiFi",
  .network_select = "Выбор сети",
  .network_scanning = "Сканирование...",
  .network_connecting = "Подключение...",
  .network_connected = "Подключено",
  .network_failed = "Ошибка подключения",
  .network_no_networks = "Сети не найдены",
  .network_scan_again = "Нажмите Подтвердить для повтора",
  .network_web_server = "Веб-сервер",
  .network_server_stopped = "Сервер остановлен",
  
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
  .file_error = "Ошибка файла",
  
  // Reader
  .reader_go_to_page = "Перейти к странице",
  
  // Buttons/Actions
  .button_yes = "Да",
  .button_no = "Нет",
  
  // Confirmation dialogs
  .confirm_clear_cache_title = "Очистить кэш?",
  .confirm_clear_cache_line1 = "Будут удалены все кэши книг",
  .confirm_clear_cache_line2 = "и прогресс чтения.",
  .confirm_clear_device_title = "Очистить устройство?",
  .confirm_clear_device_line1 = "Будет стёрта внутренняя память.",
  .confirm_clear_device_line2 = "Устройство перезагрузится.",
  .confirm_factory_reset_title = "Сброс до заводских?",
  .confirm_factory_reset_line1 = "Будут удалены ВСЕ данные включая",
  .confirm_factory_reset_line2 = "настройки и учётные данные WiFi!",
  
  // FileList
  .filelist_books = "Книги",
  .filelist_books_page = "Книги (%d/%d)",
  .filelist_no_books = "Книги не найдены",
  .filelist_delete = "Удалить",
  .filelist_confirm_delete_title = "Подтверждение удаления",
  .filelist_delete_file = "Удалить этот файл?",
  .filelist_delete_folder = "Удалить эту папку?",
  .filelist_deleting = "Удаление...",
  .filelist_deleted = "Удалено",
  .filelist_delete_failed = "Ошибка удаления",
  .filelist_cannot_delete_active = "Нельзя удалить активную книгу",
  .filelist_opening_book = "Открытие книги..."
};

}  // namespace papyrix

#endif  // STRINGS_RU_H
