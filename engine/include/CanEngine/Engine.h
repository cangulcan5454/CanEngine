#pragma once
#include <functional>

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
    };
}
