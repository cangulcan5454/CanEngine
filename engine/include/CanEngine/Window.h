#pragma once
#include <string>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace CanEngine{

    class Window{

        public:
        bool Create(int width, int height, const std::string& title);
        void Destroy();
        bool ShouldClose() const;
        void PollEvents();
        int GetWidth() const;
        int GetHeight() const;
        GLFWwindow* GetNativeWindow() const;
        private:
        int width = 0;
        int height = 0;
        std::string title;
        GLFWwindow* window = nullptr;
        static void WindowSizeCallback(
            GLFWwindow* nativeWindow,
            int width,
            int height
        );
        static void WindowCloseCallback(
            GLFWwindow* nativeWindow
        );
    };
}