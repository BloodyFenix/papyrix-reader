#ifndef STRINGS_EN_H
#define STRINGS_EN_H

#include "LocalizationTypes.h"

namespace papyrix {

// English strings
constexpr LocalizedStrings STRINGS_EN = {
  // Home screen
  .home_no_book = "No book open",
  .home_press_files = "Press \"Files\" to browse",
  
  // Button labels
  .btn_files = "Files",
  .btn_sync = "Sync",
  .btn_settings = "Settings",
  .btn_read = "Read",
  .btn_back = "Back",
  .btn_select = "Select",
  .btn_menu = "Menu",
  .btn_home = "Home",
  .btn_open = "Open",
  .btn_run = "Run",
  .btn_confirm = "Confirm",
  .btn_left = "<",
  .btn_right = ">",
  
  // Menu titles
  .title_files = "Files",
  .title_chapters = "Chapters",
  .title_settings = "Settings",
  .title_cleanup = "Cleanup",
  .title_system_info = "System Info",
  .title_reader = "Reader",
  .title_device = "Device",
  .title_network = "Network",
  .title_calibre_sync = "Calibre Sync",
  .title_sync = "Sync",
  
  // Sync menu items
  .sync_file_transfer = "File Transfer",
  .sync_calibre_wireless = "Calibre Wireless",
  
  // Settings menu items
  .settings_reader = "Reader",
  .settings_device = "Device",
  .settings_cleanup = "Cleanup",
  .settings_system_info = "System Info",
  
  // Reader menu items
  .reader_menu = "Menu",
  .reader_chapters = "Chapters",
  .reader_settings = "Settings",
  .reader_home = "Home",
  
  // Reader settings
  .reader_theme = "Theme",
  .reader_font_size = "Font Size",
  .reader_text_layout = "Text Layout",
  .reader_line_spacing = "Line Spacing",
  .reader_text_aa = "Text Anti-Aliasing",
  .reader_alignment = "Paragraph Alignment",
  .reader_hyphenation = "Hyphenation",
  .reader_show_images = "Show Images",
  .reader_status_bar = "Status Bar",
  .reader_orientation = "Reading Orientation",
  
  // Font size values
  .font_size_xs = "XSmall",
  .font_size_s = "Small",
  .font_size_m = "Normal",
  .font_size_l = "Large",
  
  // Text layout values
  .layout_compact = "Compact",
  .layout_standard = "Standard",
  .layout_large = "Large",
  
  // Line spacing values
  .spacing_tight = "Tight",
  .spacing_normal = "Normal",
  .spacing_relaxed = "Relaxed",
  .spacing_loose = "Loose",
  
  // Alignment values
  .align_justified = "Justified",
  .align_left = "Left",
  .align_center = "Center",
  .align_right = "Right",
  
  // Status bar values
  .status_bar_none = "None",
  .status_bar_title = "Title",
  .status_bar_chapter = "Chapter",
  
  // Orientation values
  .orient_portrait = "Portrait",
  .orient_landscape_cw = "Landscape CW",
  .orient_inverted = "Inverted",
  .orient_landscape_ccw = "Landscape CCW",
  
  // Device settings
  .device_sleep_timeout = "Auto Sleep Timeout",
  .device_sleep_screen = "Sleep Screen",
  .device_startup = "Startup Behavior",
  .device_short_pwr = "Short Power Button",
  .device_pages_refresh = "Pages Per Refresh",
  .device_sunlight_fix = "Sunlight Fading Fix",
  .device_front_buttons = "Front Buttons",
  .device_side_buttons = "Side Buttons",
  .device_language = "Language",
  
  // Sleep timeout values
  .sleep_5min = "5 minutes",
  .sleep_10min = "10 minutes",
  .sleep_30min = "30 minutes",
  .sleep_1hour = "1 hour",
  .sleep_never = "Never",
  .sleep_sleeping = "SLEEPING",
  
  // Sleep screen values
  .sleep_screen_blank = "Blank",
  .sleep_screen_logo = "Logo",
  .sleep_screen_cover = "Book Cover",
  .sleep_screen_last_page = "Last Page",
  
  // Startup values
  .startup_home = "Home Screen",
  .startup_last_book = "Last Book",
  
  // Short power button values
  .short_pwr_sleep = "Sleep",
  .short_pwr_menu = "Menu",
  .short_pwr_nothing = "Nothing",
  
  // Pages refresh values
  .pages_refresh_1 = "Every page",
  .pages_refresh_3 = "Every 3 pages",
  .pages_refresh_5 = "Every 5 pages",
  .pages_refresh_10 = "Every 10 pages",
  .pages_refresh_never = "Never",
  
  // Toggle values
  .toggle_on = "On",
  .toggle_off = "Off",
  
  // Button mapping values
  .buttons_page_turn = "Page Turn",
  .buttons_disabled = "Disabled",
  
  // Cleanup menu
  .cleanup_book_cache = "Clear Book Cache",
  .cleanup_device_storage = "Clear Device Storage",
  .cleanup_factory_reset = "Factory Reset",
  
  // System info labels
  .info_version = "Version",
  .info_uptime = "Uptime",
  .info_battery = "Battery",
  .info_chip = "Chip",
  .info_cpu = "CPU",
  .info_free_memory = "Free Memory",
  .info_internal_disk = "Internal Disk",
  .info_sd_card = "SD Card",
  .info_sd_ready = "Ready",
  .info_sd_not_available = "Not available",
  
  // Network
  .network_mode = "Network Mode",
  .network_mode_connect = "Connect to existing WiFi",
  .network_mode_hotspot = "Create WiFi hotspot",
  .network_select = "Select Network",
  .network_scanning = "Scanning...",
  .network_connecting = "Connecting...",
  .network_connected = "Connected",
  .network_failed = "Connection Failed",
  .network_no_networks = "No networks found",
  .network_scan_again = "Press Confirm to scan again",
  .network_web_server = "Web Server",
  .network_server_stopped = "Server stopped",
  
  // Calibre sync
  .calibre_connecting = "Connecting to Calibre...",
  .calibre_syncing = "Syncing books...",
  .calibre_complete = "Sync complete",
  .calibre_error = "Sync error",
  
  // Messages
  .msg_loading = "Loading...",
  .msg_error = "Error",
  .msg_success = "Success",
  .msg_processing = "Processing...",
  .msg_please_wait = "Please wait...",
  
  // File operations
  .file_opening = "Opening file...",
  .file_parsing = "Parsing...",
  .file_error = "File error",
  
  // Reader
  .reader_go_to_page = "Go to Page",
  
  // Buttons/Actions
  .button_yes = "Yes",
  .button_no = "No",
  
  // Confirmation dialogs
  .confirm_clear_cache_title = "Clear Caches?",
  .confirm_clear_cache_line1 = "This will delete all book caches",
  .confirm_clear_cache_line2 = "and reading progress.",
  .confirm_clear_device_title = "Clear Device?",
  .confirm_clear_device_line1 = "This will erase internal flash",
  .confirm_clear_device_line2 = "storage. Device will restart.",
  .confirm_factory_reset_title = "Factory Reset?",
  .confirm_factory_reset_line1 = "This will erase ALL data including",
  .confirm_factory_reset_line2 = "settings and WiFi credentials!"
};

}  // namespace papyrix

#endif  // STRINGS_EN_H
