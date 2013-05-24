How many times have you wished you could do this in C++:
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
    // something completely different
    break;
}
```
What are the alternatives?

1. Use `if`s - ugly, slow, and hard to maintain:
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
    // something completely different
}
```
1. Use `if`s but optimize things a bit:
```
```
