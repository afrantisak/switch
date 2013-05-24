How many times have you wished you could `switch` on a string?  Now you can:
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
Plus its templatized so you can switch on `int`s or anything else.  Its implemented using a `std::map<>` so you get the benefits of that implementation.
No compile-time duplicate checking or the ability to pass-through without a `break`, but I think those were premature optimizations anyway. 
Full background: https://github.com/afrantisak/switch/wiki

