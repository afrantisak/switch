#include "switch.h"
#include <iostream>
#include <string>
		
int main(int argc, const char* argv[])
{    
    Switch(std::string(argv[1])).
    Case("apple", []()
    {
        std::cout << "APPLE" << std::endl; 
    }).
    Case("aardvark", []()
    {
        std::cout << "AARDVARK" << std::endl; 
    }).
    Case("banana", []()
    {
        std::cout << "BANANA" << std::endl; 
    }).
    Default([]()
    {
        std::cout << "UNKNOWN" << std::endl; 
    });    

    Switch(std::string(argv[1]))
    ("apple", []()
    {
        std::cout << "APPLE" << std::endl; 
    })
    ("aardvark", []()
    {
        std::cout << "AARDVARK" << std::endl; 
    })
    ("banana", []()
    {
        std::cout << "BANANA" << std::endl; 
    })
    ([]()
    {
        std::cout << "UNKNOWN" << std::endl; 
    });    

    return 0;
}
