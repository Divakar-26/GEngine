#pragma once
#include"GEngine/gepch.h"
#include"GEngine/Core.h"
#include"Event.h"


namespace GEngine{
    class GE_API KeyEvent : public Event{
        inline int GetKeyCode() const{return m_KeyCode;}

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
        protected:
        KeyEvent(int keycode) : m_KeyCode(keycode) {}

        int m_KeyCode;
    };

    class GE_API KeyPressedEvent : public KeyEvent{
        public:
        KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode) , m_RepeatCount(repeatCount) {}

        inline int GetRepeatCount() const {return m_RepeatCount;}

        std::string ToString() const override{
            std::stringstream ss;
            ss << "KeyPressedEvent: "<<m_KeyCode<<" (" << m_RepeatCount << " repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)
        private:
        int m_RepeatCount;
    };

    class GE_API KeyReleasedEvent : public KeyEvent{
        public:
        KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

        std::string ToString() const override{
            std::stringstream ss;
            ss << "KeyReleasedEvent "<<m_KeyCode;
            return ss.str();
        }
        EVENT_CLASS_TYPE(KeyReleased)
    };
}