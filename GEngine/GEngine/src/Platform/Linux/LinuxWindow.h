#pragma once
#include"GEngine/Window.h"
#include<GLFW/glfw3.h>

namespace GEngine{
    class LinuxWindow : public Window{
        public:
            LinuxWindow(const WindowProps& props);
            virtual ~LinuxWindow();

            void OnUpdate() override;

            inline unsigned int GetWidth() const override {return m_Data.Width;}
            inline unsigned int GetHeight() const override {return m_Data.Height;}

            inline void SetEventCallback(const EventCallbackFn& callback) override {m_Data.EventCallback = callback;}

            void SetVSync(bool enabled) override;
            bool IsVSync() const override;
            private:
            virtual void Init(const WindowProps& props);
            virtual void ShutDown();

            private:
            GLFWwindow * m_Window;
            struct WindowData{
                std::string Title;
                unsigned int Width, Height;
                bool VSync;

                EventCallbackFn EventCallback;
            };

            WindowData m_Data;
    };
}