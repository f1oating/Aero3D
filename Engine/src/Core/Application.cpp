#include "Application.h"

#include "Utils/Log.h"

Application::Application()
{

}

Application::~Application()
{

}

void Application::Init()
{
    LogMsg("Application Initialize");
}

void Application::Run()
{
    while (true);
}

void Application::Shutdown()
{
    LogMsg("Application Shutdown");
}