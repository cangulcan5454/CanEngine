#include<CanEngine/Window.h>
#include<CanEngine/Log.h>
#include <GLFW/glfw3.h>

namespace CanEngine {

    bool Window::Create(int width, int height, const std::string& title){
        GLFWwindow* tmpwindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if(tmpwindow == nullptr){
            Log::Error("Window cannot created");
            return false;
        }
        this->width = width;
        this->height = height;
        this->title = title;
        this->window = tmpwindow;
        return true;
    }

    void Window::Destroy(){
        if (this->window == nullptr)
        {
            return;
        }

        glfwDestroyWindow(window);
        this->window = nullptr;
    }

    bool Window::ShouldClose() const
    {
        if (window == nullptr)
        {
            return true;
        }
        
        return glfwWindowShouldClose(window);
    }

    void Window::PollEvents(){
        glfwPollEvents();
    }

    GLFWwindow* Window::GetNativeWindow() const
    {
        return window;
    }
}