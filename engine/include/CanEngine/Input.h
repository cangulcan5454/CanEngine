#pragma once
#include <CanEngine/Window.h>
#include <array>

namespace CanEngine{
    class Input{
        public:
        explicit Input(Window& window);
        bool IsKeyPressed(int key) const;
        bool IsKeyJustPressed(int key);
        bool IsMouseButtonPressed(int button) const;
        void GetMousePosition(double& x, double& y) const;
        private:
        Window& window;
        std::array<bool, 512> previousKeyStates{};
    };
}