#pragma once
#include <functional>
#include <CanEngine/Window.h>

namespace CanEngine
{
    class Engine
    {
    public:
        bool Initialize();
        void Run(std::function<void(float)> onUpdate);
        void Shutdown();
    private:
        bool initialized = false;
        Window window;
    };
}
