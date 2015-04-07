#include <windows.h>
#include <tchar.h>
#include <iostream>
using namespace std;
typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
LPFN_ISWOW64PROCESS fnIsWow64Process;
BOOL IsWow64()
{
    BOOL bIsWow64 = FALSE;
    fnIsWow64Process = (LPFN_ISWOW64PROCESS) GetProcAddress(
        GetModuleHandle(TEXT("kernel32")),"IsWow64Process");

    if(NULL != fnIsWow64Process)
    {
        if (!fnIsWow64Process(GetCurrentProcess(),&bIsWow64))
        {
            //错误处理
        }
    }
    return bIsWow64;
}

int main(){
    if(IsWow64())
        cout<<"您的系统是64位操作系统"<<endl;
    else
        cout<<"您的系统是32位操作系统"<<endl;
	system("pause");
    return 0;
}
