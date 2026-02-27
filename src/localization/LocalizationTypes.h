#ifndef LOCALIZATION_TYPES_H
#define LOCALIZATION_TYPES_H

namespace papyrix {

// Supported languages
enum class Language {
  English,
  Russian
};

// Localization strings structure
struct LocalizedStrings {
  // Home screen
  const char* home_no_book;
  const char* home_press_files;
  
  // Button labels
  const char* btn_files;
  const char* btn_sync;
  const char* btn_settings;
  const char* btn_read;
  const char* btn_back;
  const char* btn_select;
  const char* btn_menu;
  const char* btn_home;
  const char* btn_open;
  const char* btn_run;
  const char* btn_confirm;
  const char* btn_left;   // "<"
  const char* btn_right;  // ">"
  
  // Menu titles
  const char* title_files;
  const char* title_chapters;
  const char* title_settings;
  const char* title_cleanup;
  const char* title_system_info;
  const char* title_reader;
  const char* title_device;
  const char* title_network;
  const char* title_calibre_sync;
  const char* title_sync;
  
  // Sync menu items
  const char* sync_file_transfer;
  const char* sync_calibre_wireless;
  
  // Settings menu items
  const char* settings_reader;
  const char* settings_device;
  const char* settings_cleanup;
  const char* settings_system_info;
  
  // Reader menu items
  const char* reader_menu;
  const char* reader_chapters;
  const char* reader_settings;
  const char* reader_home;
  
  // Reader settings
  const char* reader_theme;
  const char* reader_font_size;
  const char* reader_text_layout;
  const char* reader_line_spacing;
  const char* reader_text_aa;
  const char* reader_alignment;
  const char* reader_hyphenation;
  const char* reader_show_images;
  const char* reader_status_bar;
  const char* reader_orientation;
  
  // Font size values
  const char* font_size_xs;
  const char* font_size_s;
  const char* font_size_m;
  const char* font_size_l;
  
  // Text layout values
  const char* layout_compact;
  const char* layout_standard;
  const char* layout_large;
  
  // Line spacing values
  const char* spacing_tight;
  const char* spacing_normal;
  const char* spacing_relaxed;
  const char* spacing_loose;
  
  // Alignment values
  const char* align_justified;
  const char* align_left;
  const char* align_center;
  const char* align_right;
  
  // Status bar values
  const char* status_bar_none;
  const char* status_bar_title;
  const char* status_bar_chapter;
  
  // Orientation values
  const char* orient_portrait;
  const char* orient_landscape_cw;
  const char* orient_inverted;
  const char* orient_landscape_ccw;
  
  // Device settings
  const char* device_sleep_timeout;
  const char* device_sleep_screen;
  const char* device_startup;
  const char* device_short_pwr;
  const char* device_pages_refresh;
  const char* device_sunlight_fix;
  const char* device_front_buttons;
  const char* device_side_buttons;
  const char* device_language;
  
  // Sleep timeout values
  const char* sleep_5min;
  const char* sleep_10min;
  const char* sleep_30min;
  const char* sleep_1hour;
  const char* sleep_never;
  const char* sleep_sleeping;
  
  // Sleep screen values
  const char* sleep_screen_blank;
  const char* sleep_screen_logo;
  const char* sleep_screen_cover;
  const char* sleep_screen_last_page;
  
  // Startup values
  const char* startup_home;
  const char* startup_last_book;
  
  // Short power button values
  const char* short_pwr_sleep;
  const char* short_pwr_menu;
  const char* short_pwr_nothing;
  
  // Pages refresh values
  const char* pages_refresh_1;
  const char* pages_refresh_3;
  const char* pages_refresh_5;
  const char* pages_refresh_10;
  const char* pages_refresh_never;
  
  // Toggle values
  const char* toggle_on;
  const char* toggle_off;
  
  // Button mapping values
  const char* buttons_page_turn;
  const char* buttons_disabled;
  
  // Cleanup menu
  const char* cleanup_book_cache;
  const char* cleanup_device_storage;
  const char* cleanup_factory_reset;
  
  // System info labels
  const char* info_version;
  const char* info_uptime;
  const char* info_battery;
  const char* info_chip;
  const char* info_cpu;
  const char* info_free_memory;
  const char* info_internal_disk;
  const char* info_sd_card;
  const char* info_sd_ready;
  const char* info_sd_not_available;
  
  // Network
  const char* network_mode;
  const char* network_mode_connect;
  const char* network_mode_hotspot;
  const char* network_select;
  const char* network_scanning;
  const char* network_connecting;
  const char* network_connected;
  const char* network_failed;
  const char* network_no_networks;
  const char* network_scan_again;
  const char* network_web_server;
  const char* network_server_stopped;
  
  // Calibre sync
  const char* calibre_connecting;
  const char* calibre_syncing;
  const char* calibre_complete;
  const char* calibre_error;
  
  // Messages
  const char* msg_loading;
  const char* msg_error;
  const char* msg_success;
  const char* msg_processing;
  const char* msg_please_wait;
  
  // File operations
  const char* file_opening;
  const char* file_parsing;
  const char* file_error;
  
  // Reader
  const char* reader_go_to_page;
  
  // Buttons/Actions
  const char* button_yes;
  const char* button_no;
  
  // Confirmation dialogs
  const char* confirm_clear_cache_title;
  const char* confirm_clear_cache_line1;
  const char* confirm_clear_cache_line2;
  const char* confirm_clear_device_title;
  const char* confirm_clear_device_line1;
  const char* confirm_clear_device_line2;
  const char* confirm_factory_reset_title;
  const char* confirm_factory_reset_line1;
  const char* confirm_factory_reset_line2;
  
  // FileList
  const char* filelist_books;
  const char* filelist_books_page;  // "Books (%d/%d)"
  const char* filelist_no_books;
  const char* filelist_delete;
  const char* filelist_confirm_delete_title;
  const char* filelist_delete_file;  // "Delete this file?"
  const char* filelist_delete_folder;  // "Delete this folder?"
  const char* filelist_deleting;
  const char* filelist_deleted;
  const char* filelist_delete_failed;
  const char* filelist_cannot_delete_active;
  const char* filelist_opening_book;
};

}  // namespace papyrix

#endif  // LOCALIZATION_TYPES_H
