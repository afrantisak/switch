#include "switch.h"
#include <iostream>
		
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