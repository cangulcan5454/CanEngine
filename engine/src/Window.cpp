#include<CanEngine/Window.h>
#include<CanEngine/Log.h>

namespace CanEngine {

    bool Window::Create(int width, int height, const std::string& title){
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        GLFWwindow* tmpwindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if(tmpwindow == nullptr){
            Log::Error("Window cannot created");
            return false;
        }

        glfwMakeContextCurrent(tmpwindow);

        glfwSetWindowUserPointer(tmpwindow, this);
        glfwSetWindowSizeCallback(tmpwindow, WindowSizeCallback);
        glfwSetWindowCloseCallback(tmpwindow, WindowCloseCallback);
        
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

    int Window::GetWidth() const{
        return width;
    }

    int Window::GetHeight() const{
        return height;
    }

    void Window::WindowSizeCallback(
        GLFWwindow* nativeWindow,
        int width,
        int height
    )
    {
        Window* self = static_cast<Window*>(
            glfwGetWindowUserPointer(nativeWindow)
        );

        if (self == nullptr)
        {
            return;
        }

        self->width = width;
        self->height = height;

        Log::Info("Window resized: " + std::to_string(width) + " x " + std::to_string(height));
    }

    void Window::WindowCloseCallback(GLFWwindow* nativeWindow){
         Window* self = static_cast<Window*>(
            glfwGetWindowUserPointer(nativeWindow)
        );

        if (self == nullptr)
        {
            return;
        }

        Log::Info("Window close requested.");
    }
}