#ifndef LOCALIZATION_H
#define LOCALIZATION_H

#include "localization/LocalizationTypes.h"
#include "localization/strings_en.h"
#include "localization/strings_ru.h"

namespace papyrix {

// Localization manager class
class Localization {
public:
  static void setLanguage(Language lang);
  static Language getLanguage();
  static const LocalizedStrings& strings();
  
private:
  static Language currentLanguage_;
  static const LocalizedStrings* currentStrings_;
};

// Convenience macro for accessing localized strings
#define L10N papyrix::Localization::strings()

}  // namespace papyrix

#endif  // LOCALIZATION_H
