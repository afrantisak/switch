How many times have you wished you could do this in C++:
```
const char* pstr = "asdf";
switch (pstr)
{
case "asdf":
    // do something
    break;
case "qwer":
    // do something else
    break;
default:
    // something completely different
    break;
}
```
What are the alternatives?
1. Use `if`s - ugly and hard to maintain
```
const char* pstr = "asdf";
if (strcmp(pstr, "asdf") == 0)
{
    // do something
}
else if (strcmp(pstr, "qwer") == 0)
{
    // do something else
}
else
{
    // something completely different
}
```