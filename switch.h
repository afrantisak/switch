#include <iostream>
#include <functional>
#include <memory>
#include <map>

template<typename Key>
class Switcher
{
    public:
        typedef std::function<void()> Func;
        
        Switcher(Key key)
            :   m_impl(),
                m_default(),
                m_key(key)
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

        ~Switcher()
        {
            auto iFunc = m_impl.find(m_key);
            if (iFunc != m_impl.end())
            {
                iFunc->second();
            }
            else
            {
                m_default();
            }
        }

    private:
        typedef std::map<Key, Func> Impl;
        Impl m_impl;
        Func m_default;
        Key m_key;
};

template<typename Key>
class SwitcherWrap
{
    public:
        typedef typename Switcher<Key>::Func Func;
        
        SwitcherWrap(Key key)
            :   m_pImpl(new Switcher<Key>(key))
        {
        }
        
        SwitcherWrap& Case(Key key, Func func)
        {
            m_pImpl->Case(key, func);
            return *this;
        }

        SwitcherWrap& Default(Func func)
        {
            m_pImpl->Default(func);
            return *this;
        }

    private:
        std::unique_ptr<Switcher<Key>> m_pImpl;
};

template<typename Key>
SwitcherWrap<Key> Switch(Key key)
{
    return SwitcherWrap<Key>(key);
}
