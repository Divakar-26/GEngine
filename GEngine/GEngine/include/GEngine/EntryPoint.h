#pragma once
#include "Application.h"
#include <iostream>

extern GEngine::Application *GEngine::createApplication();

int main(int argc, char **argv)
{
    std::cout << "HEllo\n";
    auto app = GEngine::createApplication();
    app->Run();
    delete app;
    return 0;
}