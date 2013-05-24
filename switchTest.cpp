#include <iostream>
#include "switch.h"
#include <string.h>
		
int main(int argc, const char* argv[])
{    
    Switch(std::string(argv[1]))
    ("a", []()
    {
        std::cout << "A" << std::endl; 
    })
    ("b", []()
    {
        std::cout << "B" << std::endl; 
    })
    ([]()
    {
        std::cout << "default" << std::endl; 
    });
    
    return 0;
}
