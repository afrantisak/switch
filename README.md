How many times have you wished you could `switch` on a string?
```
const char* pstr = "asdf";
switch (pstr)
{
case "apple":
    std::cout << "APPLE" << std::endl;
    break;
case "aardvark":
    std::cout << "AARDVARK" << std::endl;
    break;
case "banana":
    std::cout << "BANANA" << std::endl;
    break;
default:
    std::cout << "UNKNOWN" << std::endl;
    break;
}
```
Now you can!
```
Switch(pstr).
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
```
Not exactly the same.  You don't get duplicate checking or the ability to pass-through without a `break`, but I think thats actually a feature. 
Full background: https://github.com/afrantisak/switch/wiki

