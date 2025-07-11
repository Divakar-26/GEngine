#pragma once
#include "Application.h"
#include "Log.h"
#include <iostream>

extern GEngine::Application *GEngine::createApplication();

int main(int argc, char **argv)
{
    GEngine::Log::Init();
    GE_CORE_WARN("Initialized Log");
    GE_INFO("Hello");
    auto app = GEngine::createApplication();
    app->Run();
    delete app;
    return 0;
}