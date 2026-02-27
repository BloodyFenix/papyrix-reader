// Simple i18n library for Papyrix web interface
// Loads translations from separate language files
// Gets system language from device API

let translations = {};
let currentLang = 'en';
let systemLang = null;
let isInitializing = false;
let isInitialized = false;

// Load translation file dynamically
async function loadTranslations(lang) {
  try {
    const script = document.createElement('script');
    script.src = `/i18n/${lang}.js`;
    
    return new Promise((resolve, reject) => {
      script.onload = () => {
        // Translation file should define translations_XX variable
        const translationsVar = window[`translations_${lang}`];
        if (translationsVar) {
          translations[lang] = translationsVar;
          resolve();
        } else {
          reject(new Error(`Translations not found for ${lang}`));
        }
      };
      script.onerror = () => reject(new Error(`Failed to load ${lang}.js`));
      document.head.appendChild(script);
    });
  } catch (error) {
    console.error(`Error loading translations for ${lang}:`, error);
    throw error;
  }
}

// Get system language from device
async function getSystemLanguage() {
  try {
    const response = await fetch('/api/language');
    if (response.ok) {
      const data = await response.json();
      // API should return { language: 'en' } or { language: 'ru' }
      return data.language || 'en';
    }
  } catch (error) {
    console.warn('Failed to get system language from device:', error);
  }
  return null;
}

// Detect browser language as fallback
function detectBrowserLanguage() {
  const browserLang = navigator.language || navigator.userLanguage;
  const langCode = browserLang.split('-')[0]; // Get 'ru' from 'ru-RU'
  
  // Check if we support this language
  const supportedLangs = ['en', 'ru'];
  if (supportedLangs.includes(langCode)) {
    return langCode;
  }
  
  // Default to English
  return 'en';
}

// Determine which language to use
async function determineLanguage() {
  // Priority 1: System language from device (always use device language by default)
  systemLang = await getSystemLanguage();
  if (systemLang) {
    // Check if user has explicitly changed language AND it differs from system
    const saved = localStorage.getItem('papyrix-web-lang');
    const userChanged = localStorage.getItem('papyrix-web-lang-user-set');
    
    // If user explicitly changed language AND it's different from system language, use their preference
    if (saved && userChanged === 'true' && saved !== systemLang) {
      return saved;
    }
    
    // Otherwise always use system language (this clears old localStorage values)
    if (saved !== systemLang) {
      localStorage.removeItem('papyrix-web-lang-user-set');
    }
    return systemLang;
  }
  
  // Priority 2: Saved user preference (fallback if API fails)
  const saved = localStorage.getItem('papyrix-web-lang');
  if (saved) {
    return saved;
  }
  
  // Priority 3: Browser language
  return detectBrowserLanguage();
}

// Get translation
function t(key) {
  const translation = translations[currentLang]?.[key];
  if (translation) {
    return translation;
  }
  
  // Fallback to English
  const fallback = translations.en?.[key];
  if (fallback) {
    return fallback;
  }
  
  // Return key if no translation found
  console.warn(`Translation missing for key: ${key}`);
  return key;
}

// Apply translations to elements with data-i18n attribute
function applyTranslations() {
  // Translate text content
  document.querySelectorAll('[data-i18n]').forEach(element => {
    const key = element.getAttribute('data-i18n');
    const translation = t(key);
    
    // Check if element has data-i18n-attr to translate attribute instead of text
    const attr = element.getAttribute('data-i18n-attr');
    if (attr) {
      element.setAttribute(attr, translation);
    } else {
      element.textContent = translation;
    }
  });
  
  // Translate placeholder attributes
  document.querySelectorAll('[data-i18n-placeholder]').forEach(element => {
    const key = element.getAttribute('data-i18n-placeholder');
    const translation = t(key);
    element.setAttribute('placeholder', translation);
  });
}

// Change language manually
async function setLanguage(lang) {
  try {
    // Load translations if not already loaded
    if (!translations[lang]) {
      await loadTranslations(lang);
    }
    
    currentLang = lang;
    localStorage.setItem('papyrix-web-lang', lang);
    localStorage.setItem('papyrix-web-lang-user-set', 'true');
    applyTranslations();
    
    return true;
  } catch (error) {
    console.error(`Failed to set language to ${lang}:`, error);
    return false;
  }
}

// Initialize i18n system
async function initI18n() {
  // Prevent multiple simultaneous initializations
  if (isInitializing) {
    // Wait for initialization to complete
    return new Promise((resolve) => {
      const checkInit = setInterval(() => {
        if (isInitialized) {
          clearInterval(checkInit);
          resolve();
        }
      }, 50);
    });
  }
  
  if (isInitialized) {
    applyTranslations();
    return;
  }
  
  isInitializing = true;
  
  try {
    // Determine which language to use
    const lang = await determineLanguage();
    
    // Load English (always needed as fallback)
    if (!translations.en) {
      await loadTranslations('en');
    }
    
    // Load target language if different from English
    if (lang !== 'en' && !translations[lang]) {
      await loadTranslations(lang);
    }
    
    currentLang = lang;
    
    // Apply translations after DOM is ready
    if (document.readyState === 'loading') {
      await new Promise(resolve => {
        document.addEventListener('DOMContentLoaded', resolve, { once: true });
      });
    }
    
    applyTranslations();
    
    isInitialized = true;
    isInitializing = false;
    
    // Dispatch event to notify that i18n is ready
    window.dispatchEvent(new CustomEvent('i18n-ready', { detail: { language: lang } }));
    
  } catch (error) {
    console.error('Failed to initialize i18n:', error);
    isInitializing = false;
    // Fallback to English
    currentLang = 'en';
    if (translations.en) {
      applyTranslations();
    }
    isInitialized = true;
  }
}

// Initialize on page load
if (document.readyState === 'loading') {
  document.addEventListener('DOMContentLoaded', initI18n);
} else {
  initI18n();
}

// Export for use in other scripts
window.i18n = {
  t,
  init: initI18n,
  setLanguage,
  getCurrentLanguage: () => currentLang,
  getSystemLanguage: () => systemLang,
  getAvailableLanguages: () => Object.keys(translations),
  isReady: () => isInitialized,
  applyTranslations
};
