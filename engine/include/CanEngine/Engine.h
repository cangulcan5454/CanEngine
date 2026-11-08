#pragma once
#include <functional>
#include <CanEngine/Window.h>
#include <CanEngine/Input.h>

namespace CanEngine
{
    class Engine
    {
    public:
        Engine();
        bool Initialize();
        void Run(std::function<void(float)> onUpdate);
        void Shutdown();
        bool IsKeyPressed(int key) const;
        bool IsKeyJustPressed(int key);
        void GetMousePosition(double& x, double& y) const;
        bool IsMouseButtonPressed(int button) const;
    private:
        bool initialized = false;
        Window window;
        Input input;

    };
}
