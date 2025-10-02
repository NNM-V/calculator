#ifndef _YEESNO_H
#define _YEESNO_H

#include <iostream>

class YesNo{
    char input;
    std::string message;
    public:
        YesNo(const std::string& msg):message(msg){}
        ~YesNo(){}

    char cont();
};

#endif //_YEESNO_H