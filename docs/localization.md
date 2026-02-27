# Локализация Papyrix Reader

## Обзор

Papyrix Reader поддерживает многоязычный интерфейс через систему локализации. В настоящее время поддерживаются следующие языки:

- **English** (Английский) - язык по умолчанию
- **Русский** (Russian)

## Архитектура

Система локализации состоит из следующих компонентов:

### 1. Localization.h

Заголовочный файл, содержащий:
- Перечисление `Language` с поддерживаемыми языками
- Структуру `LocalizedStrings` со всеми переводимыми строками
- Константы `STRINGS_EN` и `STRINGS_RU` с переводами
- Класс `Localization` для управления текущим языком
- Макрос `L10N` для удобного доступа к строкам

### 2. Localization.cpp

Файл реализации класса `Localization`:
- Управление текущим языком
- Переключение между языками
- Доступ к локализованным строкам

### 3. Интеграция в UI

Все UI компоненты используют макрос `L10N` для доступа к локализованным строкам вместо хардкода.

## Использование

### Доступ к локализованным строкам

```cpp
#include "Localization.h"

// Использование макроса L10N
const char* text = L10N.home_no_book;
r.drawText(fontId, x, y, L10N.btn_files, color);
```

### Смена языка

```cpp
#include "Localization.h"

// Установить русский язык
papyrix::Localization::setLanguage(papyrix::Language::Russian);

// Установить английский язык
papyrix::Localization::setLanguage(papyrix::Language::English);

// Получить текущий язык
papyrix::Language current = papyrix::Localization::getLanguage();
```

### Настройка языка в UI

Язык можно изменить через:
1. Settings → Device → Language
2. Выбрать "English" или "Русский"
3. Изменения применяются немедленно

## Добавление нового языка

### Шаг 1: Добавить язык в перечисление

В `src/Localization.h`:

```cpp
enum class Language {
  English,
  Russian,
  German,  // Новый язык
  // ... другие языки
};
```

### Шаг 2: Создать структуру переводов

В `src/Localization.h`:

```cpp
// German strings
constexpr LocalizedStrings STRINGS_DE = {
  .home_no_book = "Kein Buch geöffnet",
  .home_press_files = "Drücken Sie \"Dateien\" zum Durchsuchen",
  .btn_files = "Dateien",
  .btn_sync = "Sync",
  .btn_settings = "Einstellungen",
  // ... все остальные строки
};
```

### Шаг 3: Обновить метод setLanguage

В `src/Localization.cpp`:

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
    case Language::German:
      currentStrings_ = &STRINGS_DE;
      break;
    default:
      currentStrings_ = &STRINGS_EN;
      break;
  }
}
```

### Шаг 4: Добавить в настройки

В `src/ui/views/SettingsViews.h`:

```cpp
static constexpr const char* const LANGUAGE_VALUES[] = {
  "English", 
  "Русский", 
  "Deutsch"  // Добавить новый язык
};
```

Обновить количество значений в соответствующем месте.

## Структура LocalizedStrings

### Категории строк

#### Home screen (Главный экран)
- `home_no_book` - "Книга не открыта"
- `home_press_files` - Подсказка для открытия файлов

#### Button labels (Метки кнопок)
- `btn_files`, `btn_sync`, `btn_settings`, `btn_read`, `btn_back`, etc.

#### Menu titles (Заголовки меню)
- `title_files`, `title_chapters`, `title_settings`, etc.

#### Settings (Настройки)
- Reader settings: `reader_theme`, `reader_font_size`, etc.
- Device settings: `device_sleep_timeout`, `device_language`, etc.

#### Values (Значения настроек)
- Font sizes: `font_size_xs`, `font_size_s`, `font_size_m`, `font_size_l`
- Layouts: `layout_compact`, `layout_standard`, `layout_large`
- Alignments: `align_justified`, `align_left`, `align_center`, `align_right`
- И т.д.

#### Messages (Сообщения)
- `msg_loading`, `msg_error`, `msg_success`, `msg_processing`

#### Network & Sync (Сеть и синхронизация)
- `network_scanning`, `network_connecting`, `calibre_syncing`, etc.

## Рекомендации по переводу

### 1. Длина строк

Учитывайте, что разные языки имеют разную длину слов:
- Немецкий обычно длиннее английского
- Русский может быть короче или длиннее в зависимости от контекста
- Проверяйте, что текст помещается в UI элементы

### 2. Контекст

Некоторые слова имеют разное значение в зависимости от контекста:
- "Read" может быть глаголом (читать) или прилагательным (прочитанный)
- Учитывайте контекст использования при переводе

### 3. Сокращения

Для кнопок с ограниченным пространством используйте сокращения:
- "Sync" вместо "Synchronization"
- "Синхр." вместо "Синхронизация"

### 4. Форматирование

Сохраняйте специальные символы:
- Кавычки: `"Files"` → `\"Файлы\"`
- Многоточие: `"Loading..."` → `"Загрузка..."`

### 5. Консистентность

Используйте одинаковые термины для одинаковых понятий:
- "Settings" всегда переводится как "Настройки"
- "Device" всегда как "Устройство"

## Тестирование локализации

### Чек-лист

- [ ] Все строки переведены
- [ ] Нет хардкода в UI компонентах
- [ ] Текст помещается в UI элементы
- [ ] Переключение языка работает корректно
- [ ] Настройки сохраняются после перезагрузки
- [ ] Специальные символы отображаются правильно
- [ ] Кириллица отображается корректно (для русского)

### Тестовые сценарии

1. **Переключение языка:**
   - Открыть Settings → Device → Language
   - Выбрать другой язык
   - Проверить, что весь интерфейс обновился

2. **Навигация:**
   - Пройти по всем экранам
   - Проверить все меню и подменю
   - Убедиться, что все тексты переведены

3. **Длинные строки:**
   - Проверить отображение длинных названий книг
   - Проверить длинные пути к файлам
   - Убедиться, что текст не обрезается некорректно

4. **Специальные символы:**
   - Проверить отображение кириллицы
   - Проверить специальные символы (кавычки, тире, и т.д.)

## Поддержка шрифтов

### Кириллица

Для корректного отображения русского языка необходимо:
- Использовать шрифты с поддержкой кириллицы
- Убедиться, что шрифты загружены в прошивку
- Проверить, что все символы отображаются корректно

### Другие алфавиты

При добавлении языков с другими алфавитами (арабский, китайский, и т.д.):
- Убедитесь, что шрифты поддерживают нужные символы
- Учитывайте направление письма (RTL для арабского)
- Проверьте размер шрифтов в памяти

## Сохранение настроек

Выбранный язык сохраняется в настройках устройства и восстанавливается при загрузке.

### Файл настроек

Язык хранится в конфигурационном файле как индекс:
- 0 = English
- 1 = Русский
- и т.д.

### Инициализация

При запуске прошивки:
1. Загружаются настройки из файла
2. Устанавливается сохраненный язык
3. Если настройка отсутствует, используется English по умолчанию

## Примеры использования

### Пример 1: Простой текст

```cpp
#include "Localization.h"

void drawTitle(const GfxRenderer& r, const Theme& t) {
  r.drawText(t.uiFontId, 10, 10, L10N.title_settings, t.primaryTextBlack);
}
```

### Пример 2: Условный текст

```cpp
#include "Localization.h"

void drawStatus(const GfxRenderer& r, const Theme& t, bool connected) {
  const char* status = connected ? L10N.network_connected : L10N.network_failed;
  r.drawText(t.uiFontId, 10, 10, status, t.primaryTextBlack);
}
```

### Пример 3: Кнопки

```cpp
#include "Localization.h"

void setupButtons(ButtonBar& buttons) {
  buttons.labels[0] = L10N.btn_back;
  buttons.labels[1] = L10N.btn_select;
  buttons.labels[2] = "";
  buttons.labels[3] = "";
}
```

## Отладка

### Проверка текущего языка

```cpp
#include "Localization.h"
#include <Logging.h>

void debugLanguage() {
  Language lang = Localization::getLanguage();
  if (lang == Language::English) {
    LOG_INF("LANG", "Current language: English");
  } else if (lang == Language::Russian) {
    LOG_INF("LANG", "Current language: Russian");
  }
}
```

### Проверка строк

```cpp
#include "Localization.h"
#include <Logging.h>

void debugStrings() {
  LOG_INF("L10N", "home_no_book: %s", L10N.home_no_book);
  LOG_INF("L10N", "btn_files: %s", L10N.btn_files);
}
```

## Известные ограничения

1. **Динамическое переключение:** При смене языка требуется перерисовка всех экранов
2. **Размер памяти:** Каждый язык занимает дополнительную память
3. **Шрифты:** Необходимы шрифты с поддержкой всех используемых символов

## Будущие улучшения

- [ ] Автоматическое определение языка по системным настройкам
- [ ] Поддержка плюрализации (1 книга, 2 книги, 5 книг)
- [ ] Поддержка форматирования строк с параметрами
- [ ] Загрузка переводов из внешних файлов
- [ ] Инструмент для проверки полноты переводов

## Вклад в проект

При добавлении новых строк в интерфейс:

1. Добавьте строку в структуру `LocalizedStrings` в `Localization.h`
2. Добавьте перевод для всех поддерживаемых языков
3. Используйте макрос `L10N` вместо хардкода
4. Обновите эту документацию при необходимости
5. Протестируйте на всех языках

## Контакты

Если у вас есть вопросы или предложения по локализации, создайте issue в репозитории проекта.
