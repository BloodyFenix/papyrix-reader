#include "SyncViews.h"

#include "../Elements.h"
#include "Localization.h"

namespace ui {

constexpr const char* const SyncMenuView::ITEMS[];

void render(const GfxRenderer& r, const Theme& t, const SyncMenuView& v) {
  r.clearScreen(t.backgroundColor);

  title(r, t, t.screenMarginTop, L10N.title_sync);

  // Localized sync menu items
  const char* items[] = {
    L10N.sync_file_transfer,
    L10N.sync_calibre_wireless
  };

  const int startY = 60;
  for (int i = 0; i < SyncMenuView::ITEM_COUNT; i++) {
    const int y = startY + i * (t.itemHeight + t.itemSpacing);
    menuItem(r, t, y, items[i], i == v.selected);
  }

  buttonBar(r, t, v.buttons);

  r.displayBuffer();
}

}  // namespace ui
