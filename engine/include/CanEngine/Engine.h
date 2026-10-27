#pragma once
#include <functional>

namespace CanEngine
{
    class Engine
    {
    public:
        void Run(std::function<void(float)> onUpdate);
    };
}
