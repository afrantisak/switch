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
What are the alternatives?

1. Use `if`s - This is everyone's first try.
```
const char* pstr = "asdf";
if (strcmp(pstr, "apple") == 0)
{
    std::cout << "APPLE" << std::endl;
}
else if (strcmp(pstr, "aardvark") == 0)
{
    std::cout << "AARDVARK" << std::endl;
}
else if (strcmp(pstr, "banana") == 0)
{
    std::cout << "BANANA" << std::endl;
}
else
{
    std::cout << "UNKNOWN" << std::endl;
}
```
This is ugly, slow, and hard to maintain.
1. Optimized `if`s.  If speed is an issue and you don't like all those `strcmp`s you probably tried this:
```
if (pstr[0]) == 'a')
{
    if (strcmp(pstr, "apple") == 0)
    {
        std::cout << "APPLE" << std::endl;
    }
    else if (strcmp(pstr, "aardvark") == 0)
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
```
This is a bit faster depending on what your input data looks like and how you can structure the `if`s.
However, its even uglier and positively a nightmare to maintain.  
