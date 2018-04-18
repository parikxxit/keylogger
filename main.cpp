#include <iostream>
#include <windows.h>

// custom headers
//#include <KeyConstants.h>

using namespace std;


int main()
{
   //disable console screen
    MSG Msg;
    while(GetMessage (&Msg, NULL, 0, 0))
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

}
