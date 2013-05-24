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

//    if (pstr[0]) == 'a')
//    {
//        if (strcmp(pstr, "apple") == 0)
//        {
//            std::cout << "APPLE" << std::endl;
//        }
//        else if (strcmp(pstr, "aardvark") == 0)
//        {
//            std::cout << "AARDVARK" << std::endl;
//        }
//    }
//    else if (pstr[0] == 'b')
//    {
//        std::cout << "BANANA" << std::endl;
//    }
//    else
//    {
//        std::cout << "UNKNOWN" << std::endl;
//    }

    std::string str(pstr);
    if (str[0] == 'a')
    {
        if (str == "apple")
        {
            std::cout << "APPLE" << std::endl;
        }
        else if (str == "aardvark")
        {
            std::cout << "AARDVARK" << std::endl;
        }
    }
    else if (pstr[0] == 'b')
    {
        std::cout << "BANANA" << std::endl;
    }
    else
    {
        std::cout << "UNKNOWN" << std::endl;
    }
        
}