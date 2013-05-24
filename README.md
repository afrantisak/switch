Ever wished you could `switch` on a string?  Now you can:
```
Switch(std::string(psz)).
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

###Pros
* Implemented using a `std::map<>` so you get the benefits of its lookup.
* Templatized key so you can switch on `int`s or anything `less`-able.  

###Cons:
* No compile-time duplicate key check or the ability to pass-through without a `break`, but I think those were limiting features anyway. 

Full details: https://github.com/afrantisak/switch/wiki

