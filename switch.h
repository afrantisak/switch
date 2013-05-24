#pragma once
#include <functional>
#include <memory>
#include <map>
#include <iostream>

namespace Private
{

    template<typename Key>
    class SwitchImpl
    {
        public:
            typedef std::function<void()> Func;
            
            SwitchImpl(Key key)
                :   m_impl(),
                    m_default(),
                    m_key(key)
            {
            }
            
            SwitchImpl& Case(Key key, Func func)
            {
                m_impl.insert(std::make_pair(key, func));
                return *this;
            }

            SwitchImpl& Default(Func func)
            {
                m_default = func;
                return *this;
            }

            SwitchImpl& operator()(Key key, Func func)
            {
                return Case(key, func);
            }
            
            SwitchImpl& operator()(Func func)
            {
                return Default(func);
            }

            ~SwitchImpl()
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

};// namespace Private

template<typename Key>
Private::SwitchImpl<Key> Switch(Key key)
{
    return Private::SwitchImpl<Key>(key);
}
