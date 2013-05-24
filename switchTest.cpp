#include "switch.h"
#include <iostream>
#include <string.h>
		
int main(int argc, const char* argv[])
{    
    Switch(argv[1]).
    Case("a", []()
    {
        std::cout << "A" << std::endl; 
    }).
    Case("b", []()
    {
        std::cout << "B" << std::endl; 
    }).
    Default([]()
    {
        std::cout << "default" << std::endl; 
    });
    
    return 0;
}

int test()
{
    const char* pstr = "asdf";
//    switch (pstr)
//    {
//    case "asdf":
//        // do something
//        break;
//    case "qwer":
//        // do something else
//        break;
//    default:
//        // something completely different
//        break;
//    }

    if (strcmp(pstr, "asdf") == 0)
    {
        // do something
    }
    else if (strcmp(pstr, "qwer") == 0)
    {
        // do something else
    }
    else
    {
        // something completely different
    }
    
}