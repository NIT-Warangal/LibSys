
//---------------------------------------------------------------------------
#ifndef LanguageManagerH
#define LanguageManagerH
//---------------------------------------------------------------------------
#include "LanguageIds.h"
//---------------------------------------------------------------------------

class clsLanguageManager {
private:
    // ...
public:
    static clsLanguageManager * mPtr;

    char * sTexts[LANG_IDS_END]; //LanguageManager->sTexts[]
    uint16_t ui16TextsLens[LANG_IDS_END]; //LanguageManager->ui16TextsLens[]

    clsLanguageManager(void);
    ~clsLanguageManager(void);
    
	char * GetLangStr(size_t TextId); //LanguageManager->GetLangStr
	void Load();
	
	static void GenerateXmlExample();
};
//---------------------------------------------------------------------------

#endif
