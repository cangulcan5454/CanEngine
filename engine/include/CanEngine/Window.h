#pragma once
#include <string>
#include<GLFW/glfw3.h>

namespace CanEngine{

    class Window{

        public:
        bool Create(int width, int height, const std::string& title);
        void Destroy();
        bool ShouldClose() const;
        void PollEvents();
        private:
        int width = 0;
        int height = 0;
        std::string title;
        GLFWwindow* window = nullptr;
    };
}