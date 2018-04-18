#ifndef HElPER_H //this can be anything
#define HELPER_H
#include <ctime> // to retrive for every keystroke
#include <string> //to store log file
#incude <sstream> //converting to string stream

//custom namespace
namespace helper
{
    template <class T>   //typename T
    std::string Tostring(const T &) /*this function will convert everything int string for storing log*/
    struct DateTime
    {
        DateTime(); // generate time on machine where keylogger is running
        {
            time_t ms; //variable name ms
            time(&ms) //ctime function
            struct tm *info = localtime(&ms) //ctime function
            D = info->tm_mday //use info pointer to ascess attribute tm_day from struct tm and get the day
            m = info->tm_mon +1; //scince it start with 0
            y = 1900 + info->tm_year;
            M = info->tm_min;
            H = info->tm_hour;
            S = info->tm_sec;
        }
        //this constructor hrlp to create own custom time
        DateTime(int D, int m, int y, int H, int M, int S) : /*initializatoin*/  D(D), m(m), y(y), H(H), M(M), S(S) {}//create data time instance
        //if date is there and time is set to zero
        DateTime(int D, int m, int y) : D(D), m(m), y(y), H(0), M(0), S(0) {}
        DateTime Now() const
        {
            return DateTime();
        }
        int D,m,y,H,M,S;
        std::string GetDateString() const
        {//formating for date
            return std::string(D < 10 ? "0" : "") + Tostring() + std::string(m<10 ? ".0" : ".") + Tostring(m) + "." + ToString(y);
        }
        //time formating sep == seperator
        std::string GetTimeString(const std::string &sep = ":") const
        {
            return  std::string (H<10?"0" : "") + Tostring(H) + sep + std::string(M < 10 ? "0" : "") + Tostring(M) + sep + std::string(S<10 ? sep  : "") + Tostring(S);
        }
        //combination of above 2
        std::string GetDateTimeString(const std::string &sep = ":" ) const
        {
            return GetDateString() + " " + GetTimeString();
        }
    };
    //generic function to convert everything to string
    template <class T>
    std::string Tostring(const T &e)
    {
        std::ostringstream s; //var s of type ostringstream
        s << e; //variable must supprot insersion operator
        return s.str;
    }
    //create a log file for keylogger for debugging
    void WriteAppLog( const std::string &s)
    {
        std::ofstream file("AppLof.txt", std::ios::app); //append the file
        file << "[" << helper::DateTime().GetTimeString() << "]" << std::endl<< s << std::endl;
        file.close();
    }
}
#endif // HElPER_H
