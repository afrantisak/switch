#include <iostream>
#include <functional>
#include <map>

template<typename Key, typename Func = std::function<void()>>
class Switch
{
    public:
        Switch()
            :   m_impl(),
                m_default()
        {
        }

        void Case(Key key, Func func)
        {
            m_impl.insert(std::make_pair(key, func));
        }

        void Default(Func func)
        {
            m_default = func;
        }

        void operator()(Key key)
        {
            auto iFunc = m_impl.find(key);
            if (iFunc == m_impl.end())
            {
                m_default();
            }
            else
            {
                iFunc->second();
            }
        }

    private:
        typedef std::map<Key, Func> Impl;
        Impl m_impl;
        Func m_default;
};
		
int main(int argc, char* argv[])
{
    Switch<std::string> s;
    s.Case("a", []()
    {
        std::cout << "A" << std::endl; 
    });
    s.Case("b", []()
    {
        std::cout << "B" << std::endl; 
    });
    s.Default([]()
    {
        std::cout << "default" << std::endl; 
    });
    s(argv[1]);
    return 0;
}