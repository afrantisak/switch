#pragma once
#include <functional>
#include <memory>
#include <map>

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
            
            void Case(Key key, Func func)
            {
                m_impl.insert(std::make_pair(key, func));
            }

            void Default(Func func)
            {
                m_default = func;
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

    template<typename Key>
    class SwitchWrap
    {
        public:
            typedef typename SwitchImpl<Key>::Func Func;
            
            SwitchWrap(Key key)
                :   m_pImpl(new SwitchImpl<Key>(key))
            {
            }
            
            SwitchWrap& Case(Key key, Func func)
            {
                m_pImpl->Case(key, func);
                return *this;
            }

            SwitchWrap& Default(Func func)
            {
                m_pImpl->Default(func);
                return *this;
            }

        private:
            std::unique_ptr<SwitchImpl<Key>> m_pImpl;
    };

};// namespace Private

template<typename Key>
Private::SwitchWrap<Key> Switch(Key key)
{
    return Private::SwitchWrap<Key>(key);
}
