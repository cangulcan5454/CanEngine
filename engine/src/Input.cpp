#include<CanEngine/Input.h>
#include <GLFW/glfw3.h>

namespace CanEngine{

    Input::Input(Window& window)
        : window(window)
    {

    }

    bool Input::IsKeyPressed(int key) const
    {
        if (window.GetNativeWindow() == nullptr)
            return false;

        return glfwGetKey(window.GetNativeWindow(), key) == GLFW_PRESS;
    }

    bool Input::IsKeyJustPressed(int key){
        if(window.GetNativeWindow() == nullptr)
            return false;

        if (key < 0 || key >= previousKeyStates.size())
            return false;

        bool currentState = false;
        if(glfwGetKey(window.GetNativeWindow(),key) == GLFW_PRESS)
            currentState = true;
        
        bool previousState = previousKeyStates[key];

        bool result = currentState && !previousState;
        previousKeyStates[key] = currentState;
        return result;
    }

    void Input::GetMousePosition(double& x, double& y) const
    {
        if (window.GetNativeWindow() == nullptr)
        {
            x = 0;
            y = 0;
            return;
        }
        glfwGetCursorPos(window.GetNativeWindow(), &x, &y);
    }

    bool Input::IsMouseButtonPressed(int button) const
    {
        if (window.GetNativeWindow() == nullptr)
            return false;
        
        return glfwGetMouseButton(window.GetNativeWindow(),button) == GLFW_PRESS;
    }
}