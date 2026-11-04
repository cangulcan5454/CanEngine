#pragma once
#include <CanEngine/Engine.h>

namespace CanEngine
{
    class Application
    {
    public:
        void Start();
        void Run();
        
    private:
        Engine engine;

    };
}