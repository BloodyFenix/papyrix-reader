#include "SettingsViews.h"
#include "../../Localization.h"

namespace ui {

// Static definitions for constexpr arrays
constexpr const char* const SettingsMenuView::ITEMS[];
constexpr const char* const CleanupMenuView::ITEMS[];

// ReaderSettingsView static definitions
constexpr const char* const ReaderSettingsView::FONT_SIZE_VALUES[];
constexpr const char* const ReaderSettingsView::TEXT_LAYOUT_VALUES[];
constexpr const char* const ReaderSettingsView::LINE_SPACING_VALUES[];
constexpr const char* const ReaderSettingsView::ALIGNMENT_VALUES[];
constexpr const char* const ReaderSettingsView::STATUS_BAR_VALUES[];
constexpr const char* const ReaderSettingsView::ORIENTATION_VALUES[];

// Note: Labels are now set dynamically in render() using L10N
const ReaderSettingsView::SettingDef ReaderSettingsView::DEFS[SETTING_COUNT] = {
    {"", SettingType::ThemeSelect, nullptr, 0},
    {"", SettingType::Enum, FONT_SIZE_VALUES, 4},
    {"", SettingType::Enum, TEXT_LAYOUT_VALUES, 3},
    {"", SettingType::Enum, LINE_SPACING_VALUES, 4},
    {"", SettingType::Toggle, nullptr, 0},
    {"", SettingType::Enum, ALIGNMENT_VALUES, 4},
    {"", SettingType::Toggle, nullptr, 0},
    {"", SettingType::Toggle, nullptr, 0},
    {"", SettingType::Enum, STATUS_BAR_VALUES, 3},
    {"", SettingType::Enum, ORIENTATION_VALUES, 4},
};

// DeviceSettingsView static definitions
constexpr const char* const DeviceSettingsView::SLEEP_TIMEOUT_VALUES[];
constexpr const char* const DeviceSettingsView::SLEEP_SCREEN_VALUES[];
constexpr const char* const DeviceSettingsView::STARTUP_VALUES[];
constexpr const char* const DeviceSettingsView::SHORT_PWR_VALUES[];
constexpr const char* const DeviceSettingsView::PAGES_REFRESH_VALUES[];
constexpr const char* const DeviceSettingsView::TOGGLE_VALUES[];
constexpr const char* const DeviceSettingsView::FRONT_BUTTON_VALUES[];
constexpr const char* const DeviceSettingsView::SIDE_BUTTON_VALUES[];

// Note: Labels are now set dynamically in render() using L10N
const DeviceSettingsView::SettingDef DeviceSettingsView::DEFS[SETTING_COUNT] = {
    {"", SLEEP_TIMEOUT_VALUES, 5}, {"", SLEEP_SCREEN_VALUES, 4},
    {"", STARTUP_VALUES, 2},       {"", SHORT_PWR_VALUES, 3},
    {"", PAGES_REFRESH_VALUES, 5}, {"", TOGGLE_VALUES, 2},
    {"", FRONT_BUTTON_VALUES, 2},  {"", SIDE_BUTTON_VALUES, 2},
    {"", LANGUAGE_VALUES, 2},
};

// Render functions

void render(const GfxRenderer& r, const Theme& t, const SettingsMenuView& v) {
  r.clearScreen(t.backgroundColor);

  title(r, t, t.screenMarginTop, L10N.title_settings);

  // Localized menu items
  const char* items[] = {
    L10N.settings_reader,
    L10N.settings_device,
    L10N.settings_cleanup,
    L10N.settings_system_info
  };

  const int startY = 60;
  for (int i = 0; i < SettingsMenuView::ITEM_COUNT; i++) {
    const int y = startY + i * (t.itemHeight + t.itemSpacing);
    menuItem(r, t, y, items[i], i == v.selected);
  }

  buttonBar(r, t, v.buttons);

  r.displayBuffer();
}

void render(const GfxRenderer& r, const Theme& t, const CleanupMenuView& v) {
  r.clearScreen(t.backgroundColor);

  title(r, t, t.screenMarginTop, L10N.title_cleanup);

  // Localized cleanup items
  const char* items[] = {
    L10N.cleanup_book_cache,
    L10N.cleanup_device_storage,
    L10N.cleanup_factory_reset
  };

  const int startY = 60;
  for (int i = 0; i < CleanupMenuView::ITEM_COUNT; i++) {
    const int y = startY + i * (t.itemHeight + t.itemSpacing);
    menuItem(r, t, y, items[i], i == v.selected);
  }

  buttonBar(r, t, v.buttons);

  r.displayBuffer();
}

void render(const GfxRenderer& r, const Theme& t, const SystemInfoView& v) {
  r.clearScreen(t.backgroundColor);

  title(r, t, t.screenMarginTop, L10N.title_system_info);

  const int lineHeight = r.getLineHeight(t.uiFontId) + 5;
  const int startY = 60;

  for (int i = 0; i < v.fieldCount; i++) {
    const int y = startY + i * lineHeight;
    twoColumnRow(r, t, y, v.fields[i].label, v.fields[i].value);
  }

  buttonBar(r, t, v.buttons);

  r.displayBuffer();
}

void render(const GfxRenderer& r, const Theme& t, const ReaderSettingsView& v) {
  r.clearScreen(t.backgroundColor);

  title(r, t, t.screenMarginTop, L10N.settings_reader);

  // Create array of localized labels
  const char* labels[ReaderSettingsView::SETTING_COUNT] = {
    L10N.reader_theme,
    L10N.reader_font_size,
    L10N.reader_text_layout,
    L10N.reader_line_spacing,
    L10N.reader_text_aa,
    L10N.reader_alignment,
    L10N.reader_hyphenation,
    L10N.reader_show_images,
    L10N.reader_status_bar,
    L10N.reader_orientation,
  };

  const int startY = 60;
  for (int i = 0; i < ReaderSettingsView::SETTING_COUNT; i++) {
    const int y = startY + i * (t.itemHeight + t.itemSpacing);
    enumValue(r, t, y, labels[i], v.getCurrentValueStr(i), i == v.selected);
  }

  buttonBar(r, t, v.buttons);

  r.displayBuffer();
}

void render(const GfxRenderer& r, const Theme& t, const DeviceSettingsView& v) {
  r.clearScreen(t.backgroundColor);

  title(r, t, t.screenMarginTop, L10N.title_device);

  // Localized device setting labels
  const char* labels[] = {
    L10N.device_sleep_timeout,
    L10N.device_sleep_screen,
    L10N.device_startup,
    L10N.device_short_pwr,
    L10N.device_pages_refresh,
    L10N.device_sunlight_fix,
    L10N.device_front_buttons,
    L10N.device_side_buttons,
    L10N.device_language
  };

  const int startY = 60;
  for (int i = 0; i < DeviceSettingsView::SETTING_COUNT; i++) {
    const int y = startY + i * (t.itemHeight + t.itemSpacing);
    enumValue(r, t, y, labels[i], v.getCurrentValueStr(i), i == v.selected);
  }

  buttonBar(r, t, v.buttons);

  r.displayBuffer();
}

const char* ReaderSettingsView::getCurrentValueStr(int index) const {
  const auto& def = DEFS[index];
  if (def.type == SettingType::Toggle) {
    return values[index] ? L10N.toggle_on : L10N.toggle_off;
  }
  if (def.type == SettingType::ThemeSelect) {
    if (themeCount > 0 && currentThemeIndex < themeCount) {
      return themeNames[currentThemeIndex];
    }
    return "light";
  }
  
  // Bounds check to prevent array out-of-bounds access from corrupted settings
  if (def.enumCount == 0 || values[index] >= def.enumCount) {
    return "???";
  }
  
  // Return localized strings based on setting index and value
  switch (index) {
    case 1:  // Font Size
      switch (values[index]) {
        case 0: return L10N.font_size_xs;
        case 1: return L10N.font_size_s;
        case 2: return L10N.font_size_m;
        case 3: return L10N.font_size_l;
        default: return "???";
      }
    case 2:  // Text Layout
      switch (values[index]) {
        case 0: return L10N.layout_compact;
        case 1: return L10N.layout_standard;
        case 2: return L10N.layout_large;
        default: return "???";
      }
    case 3:  // Line Spacing
      switch (values[index]) {
        case 0: return L10N.spacing_tight;
        case 1: return L10N.spacing_normal;
        case 2: return L10N.spacing_relaxed;
        case 3: return L10N.spacing_loose;
        default: return "???";
      }
    case 5:  // Alignment
      switch (values[index]) {
        case 0: return L10N.align_justified;
        case 1: return L10N.align_left;
        case 2: return L10N.align_center;
        case 3: return L10N.align_right;
        default: return "???";
      }
    case 8:  // Status Bar
      switch (values[index]) {
        case 0: return L10N.status_bar_none;
        case 1: return L10N.status_bar_title;
        case 2: return L10N.status_bar_chapter;
        default: return "???";
      }
    case 9:  // Orientation
      switch (values[index]) {
        case 0: return L10N.orient_portrait;
        case 1: return L10N.orient_landscape_cw;
        case 2: return L10N.orient_inverted;
        case 3: return L10N.orient_landscape_ccw;
        default: return "???";
      }
    default:
      return def.enumValues[values[index]];
  }
}

const char* DeviceSettingsView::getCurrentValueStr(int index) const {
  const auto& def = DEFS[index];
  // Bounds check to prevent array out-of-bounds access from corrupted settings
  if (def.valueCount == 0 || values[index] >= def.valueCount) {
    return "???";
  }
  
  // Return localized strings based on setting index and value
  switch (index) {
    case 0:  // Sleep Timeout
      switch (values[index]) {
        case 0: return L10N.sleep_5min;
        case 1: return L10N.sleep_10min;
        case 2: return L10N.sleep_15min;
        case 3: return L10N.sleep_30min;
        case 4: return L10N.sleep_never;
        default: return "???";
      }
    case 1:  // Sleep Screen
      switch (values[index]) {
        case 0: return L10N.sleep_screen_dark;
        case 1: return L10N.sleep_screen_light;
        case 2: return L10N.sleep_screen_custom;
        case 3: return L10N.sleep_screen_cover;
        default: return "???";
      }
    case 2:  // Startup
      switch (values[index]) {
        case 0: return L10N.startup_last_book;
        case 1: return L10N.startup_home;
        default: return "???";
      }
    case 3:  // Short Power Button
      switch (values[index]) {
        case 0: return L10N.short_pwr_ignore;
        case 1: return L10N.short_pwr_sleep;
        case 2: return L10N.short_pwr_page_turn;
        default: return "???";
      }
    case 4:  // Pages Refresh
      switch (values[index]) {
        case 0: return L10N.pages_refresh_1;
        case 1: return L10N.pages_refresh_5;
        case 2: return L10N.pages_refresh_10;
        case 3: return L10N.pages_refresh_15;
        case 4: return L10N.pages_refresh_30;
        default: return "???";
      }
    case 5:  // Sunlight Fix (Toggle)
      return values[index] ? L10N.toggle_on : L10N.toggle_off;
    case 6:  // Front Buttons
      switch (values[index]) {
        case 0: return "B/C/L/R";  // Keep as is (button layout)
        case 1: return "L/R/B/C";
        default: return "???";
      }
    case 7:  // Side Buttons
      switch (values[index]) {
        case 0: return "Prev/Next";  // Keep as is
        case 1: return "Next/Prev";
        default: return "???";
      }
    case 8:  // Language
      return def.values[values[index]];  // Keep original (English/Русский)
    default:
      return def.values[values[index]];
  }
}

void render(const GfxRenderer& r, const Theme& t, const ConfirmDialogView& v) {
  const int pageWidth = r.getScreenWidth();
  const int pageHeight = r.getScreenHeight();
  const int lineHeight = r.getLineHeight(t.uiFontId);
  const int top = (pageHeight - lineHeight * 3) / 2;

  r.clearScreen(t.backgroundColor);

  // Title (bold, centered)
  r.drawCenteredText(t.readerFontId, top - 40, v.title, t.primaryTextBlack, EpdFontFamily::BOLD);

  // Description lines
  r.drawCenteredText(t.uiFontId, top, v.line1, t.primaryTextBlack);
  if (v.line2[0] != '\0') {
    r.drawCenteredText(t.uiFontId, top + lineHeight, v.line2, t.primaryTextBlack);
  }

  // Yes/No buttons
  const int buttonY = top + lineHeight * 3;
  constexpr int buttonWidth = 80;
  constexpr int buttonHeight = 36;
  constexpr int buttonSpacing = 20;
  constexpr int totalWidth = buttonWidth * 2 + buttonSpacing;
  const int startX = (pageWidth - totalWidth) / 2;

  const char* buttonLabels[] = {L10N.button_yes, L10N.button_no};
  const int buttonPositions[] = {startX, startX + buttonWidth + buttonSpacing};

  for (int i = 0; i < 2; i++) {
    const bool isSelected = (v.selection == i);
    const int btnX = buttonPositions[i];

    if (isSelected) {
      r.fillRect(btnX, buttonY, buttonWidth, buttonHeight, t.selectionFillBlack);
    } else {
      r.drawRect(btnX, buttonY, buttonWidth, buttonHeight, t.primaryTextBlack);
    }

    const bool textColor = isSelected ? t.selectionTextBlack : t.primaryTextBlack;
    const int textWidth = r.getTextWidth(t.uiFontId, buttonLabels[i]);
    const int textX = btnX + (buttonWidth - textWidth) / 2;
    const int textY = buttonY + (buttonHeight - r.getFontAscenderSize(t.uiFontId)) / 2;
    r.drawText(t.uiFontId, textX, textY, buttonLabels[i], textColor);
  }

  // Button hints
  buttonBar(r, t, v.buttons);

  r.displayBuffer();
}

}  // namespace ui
