#include "Localization.h"

namespace papyrix {

// Static member initialization
Language Localization::currentLanguage_ = Language::English;
const LocalizedStrings* Localization::currentStrings_ = &STRINGS_EN;

void Localization::setLanguage(Language lang) {
  currentLanguage_ = lang;
  
  switch (lang) {
    case Language::English:
      currentStrings_ = &STRINGS_EN;
      break;
    case Language::Russian:
      currentStrings_ = &STRINGS_RU;
      break;
    default:
      currentStrings_ = &STRINGS_EN;
      break;
  }
}

Language Localization::getLanguage() {
  return currentLanguage_;
}

const LocalizedStrings& Localization::strings() {
  return *currentStrings_;
}

}  // namespace papyrix
