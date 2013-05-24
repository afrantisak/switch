#include "switch.h"
#include <iostream>
#include <string>

void youTyped(std::string str)
{
    std::cout << "You typed " << str << "." << std::endl;
}

int main(int argc, const char* argv[])
{
    Switch(std::string(argv[1])).
    Case("apple",  []()
    {
        youTyped("apple");
    }).
    Case("aardvark", []()
    {
        youTyped("aardvark");
    }).
    Case("banana", []()
    {
        youTyped("banana");
    }).
    Default([]()
    {
        youTyped("something I don't understand");
    });    

    Switch(std::string(argv[1]))
    ("apple", []()
    {
        youTyped("apple");
    })
    ("aardvark", []()
    {
        youTyped("aardvark");
    })
    ("banana", []()
    {
        youTyped("banana");
    })
    ([]()
    {
        youTyped("something I don't understand");
    });    

    return 0;
}
