#include <GEngine/GEngine.h>

class Sandbox : public GEngine::Application
{
    public:
    Sandbox() {}
    ~Sandbox() {}
};


GEngine::Application * GEngine::createApplication()
{
    return new Sandbox();           
}
