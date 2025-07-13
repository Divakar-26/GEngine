#pragma once
#include"gepch.h"
#include"Core.h"
#include"Event/Event.h"


namespace GEngine{
    struct WindowProps
    {
        std::string Title;
        unsigned int Width, Height;

        WindowProps(const std::string& title="GEngine", unsigned int width = 1280, unsigned int height = 720) : Title(title), Width(width), Height(height){}

    };

    class GE_API Window{
        public:
            using EventCallbackFn = std::function<void(Event&)>;
            virtual ~Window() {}

            virtual void OnUpdate() = 0;

            virtual unsigned int GetWidth() const  = 0;
            virtual unsigned int GetHeight() const  = 0;

            //attributes
            virtual void SetEventCallback(const EventCallbackFn & callback ) = 0;
            virtual void SetVSync(bool enabled) = 0;
            virtual bool IsVSync() const = 0;

            static Window * Create(const WindowProps& pros = WindowProps());
    };
    
}