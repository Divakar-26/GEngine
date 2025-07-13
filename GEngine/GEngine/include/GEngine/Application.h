#pragma once
#include"gepch.h"
#include"Core.h"

#include"Window.h"

namespace GEngine
{
    class GE_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running;
    };

    Application * createApplication();
}