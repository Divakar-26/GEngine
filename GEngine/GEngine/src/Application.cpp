#include "GEngine/Application.h"
#include "GEngine/Event/ApplicationEvent.h"
#include "GEngine/Log.h"
#include <GLFW/glfw3.h>

namespace GEngine
{
    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Running = true;
    }

    Application::~Application()
    {
        
    }

    void Application::Run()
    {
        while (m_Running){
            m_Window->OnUpdate();
        }
    }
}