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
  
  // Settings menu items
  const char* settings_reader;
  const char* settings_device;
  const char* settings_cleanup;
  const char* settings_system_info;
  
  // Reader menu items
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
  const char* status_bar_off;
  const char* status_bar_minimal;
  const char* status_bar_full;
  
  // Orientation values
  const char* orient_portrait;
  const char* orient_landscape;
  const char* orient_portrait_inv;
  const char* orient_landscape_inv;
  
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
  const char* cleanup_cache;
  const char* cleanup_thumbnails;
  const char* cleanup_all;
  
  // System info labels
  const char* info_firmware;
  const char* info_device;
  const char* info_free_heap;
  const char* info_sd_card;
  const char* info_battery;
  const char* info_wifi_mac;
  
  // Network
  const char* network_scanning;
  const char* network_connecting;
  const char* network_connected;
  const char* network_failed;
  const char* network_no_networks;
  
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
};

}  // namespace papyrix

#endif  // LOCALIZATION_TYPES_H
