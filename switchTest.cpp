#include <iostream>
#include <functional>
#include <memory>
#include <map>

template<typename Key, typename Func = std::function<void()>>
class Switcher
{
    public:
        Switcher()
            :   m_impl(),
                m_default()
        {
        }
        
        Switcher& Case(Key key, Func func)
        {
            m_impl.insert(std::make_pair(key, func));
            return *this;
        }

        Switcher& Default(Func func)
        {
            m_default = func;
            return *this;
        }

        Switcher& operator()(Key key)
        {
            auto iFunc = m_impl.find(key);
            if (iFunc != m_impl.end())
            {
                iFunc->second();
            }
            else
            {
                m_default();
            }
            return *this;
        }

    private:
        typedef std::map<Key, Func> Impl;
        Impl m_impl;
        Func m_default;
};

template<typename Key, typename Func = std::function<void()>>
class AutoSwitcher
{
    public:
        AutoSwitcher(Key key)
            :   m_impl(),
                m_key(key)
        {
        }
        
        ~AutoSwitcher()
        {
            m_impl(m_key);
        }
        
        AutoSwitcher& Case(Key key, Func func)
        {
            m_impl.Case(key, func);
            return *this;
        }

        AutoSwitcher& Default(Func func)
        {
            m_impl.Default(func);
            return *this;
        }

    private:
        Switcher<Key, Func> m_impl;
        Key m_key;
};

template<typename Key, typename Func = std::function<void()>>
class AutoSwitcherWrap
{
    public:
        AutoSwitcherWrap(Key key)
            :   m_pImpl(new AutoSwitcher<Key, Func>(key))
        {
        }
        
        AutoSwitcherWrap& Case(Key key, Func func)
        {
            m_pImpl->Case(key, func);
            return *this;
        }

        AutoSwitcherWrap& Default(Func func)
        {
            m_pImpl->Default(func);
            return *this;
        }

    private:
        std::shared_ptr<AutoSwitcher<Key, Func>> m_pImpl;
};

template<typename Key, typename Func = std::function<void()>>
AutoSwitcherWrap<Key, Func> Switch(Key key)
{
    return AutoSwitcherWrap<Key, Func>(key);
}
		
int main(int argc, char* argv[])
{
    std::cout << "new: " << std::endl;
    
    Switch(std::string(argv[1])).
    Case(std::string("a"), []()
    {
        std::cout << "A" << std::endl; 
    }).
    Case(std::string("b"), []()
    {
        std::cout << "B" << std::endl; 
    }).
    Default([]()
    {
        std::cout << "default" << std::endl; 
    });
    
    std::cout << "old: " << std::endl;
    Switcher<std::string> s;
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