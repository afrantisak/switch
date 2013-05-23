#include "switch.h"
		
int main(int argc, char* argv[])
{    
    Switch(std::string(argv[1])).
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