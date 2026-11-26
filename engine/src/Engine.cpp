#include <CanEngine/Engine.h>
#include <CanEngine/Log.h>
#include <glad/gl.h>
#include <chrono>

namespace CanEngine
{
    Engine::Engine()
        :input(window)
    {
    }

    void Engine::Run(std::function<void(float)> onUpdate)
    {

        if (!initialized)
        {
            Log::Error("Engine is not initialized!");
            return;
        }   

        int frame = 0;

        auto previousTime = std::chrono::steady_clock::now();
        glClearColor(0.2f,0.2f,1.0f,1.0f);

        while (!window.ShouldClose())
        {
            window.PollEvents();    
            auto currentTime = std::chrono::steady_clock::now();

            std::chrono::duration<float> elapsed =
                currentTime - previousTime;

            float deltaTime = elapsed.count();
            previousTime = currentTime;

            if (onUpdate){
            onUpdate(deltaTime);}
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(window.GetNativeWindow());
            frame++;

        }
    }
    bool Engine::Initialize(){

        if (initialized){
            return false;
        }
        if(glfwInit()!=GLFW_TRUE){
            Log::Error("GLFW is not initialized");
            return false;
        }

        if(!window.Create(1280, 720, "CanEngine"))
        {
            glfwTerminate();
            return false;
        }
        
        int gladVersion = gladLoadGL((GLADloadfunc)glfwGetProcAddress);
        if(gladVersion == 0)
        {

            Log::Error("GLAD initialization failed");

            window.Destroy();
            glfwTerminate();
            return false;
        }
        int height = window.GetHeight();
        int width = window.GetWidth();
        glfwGetFramebufferSize(
            window.GetNativeWindow(),
            &width,
            &height
        );
        glViewport(0,0,width,height);
        initialized= true;
        Log::Info("CanEngine initialized. Glad version: " + std::to_string(gladVersion));
        return true;
    }

    void Engine::Shutdown(){
        if(!initialized){
            return;
        }

        window.Destroy();
        glfwTerminate();
        initialized=false;
        Log::Info("CanEngine shutdown.");
    }

    bool Engine::IsKeyPressed(int key) const{
        return input.IsKeyPressed(key);
    }

    bool Engine::IsKeyJustPressed(int key){
        return input.IsKeyJustPressed(key);
    }

    void Engine::GetMousePosition(double& x, double& y) const
    {
        input.GetMousePosition(x,y);
    }

    bool Engine::IsMouseButtonPressed(int button) const
    {
        return input.IsMouseButtonPressed(button);
    }
}