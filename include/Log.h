#ifndef _CONSOLE_H
#define _CONSOLE_H
#include<vector>
#include<string>
#include<sstream>
class Log{
    public:
        static void draw();
        static void Post(std::string);
        static void Post(const char*);
};
#endif