#include <CanEngine/Engine.h>
#include <CanEngine/Log.h>
#include <chrono>

namespace CanEngine
{
    void Engine::Run(std::function<void(float)> onUpdate)
    {

        if (!initialized)
        {
            Log::Error("Engine is not initialized!");
            return;
        }   

        int frame = 0;

        auto previousTime = std::chrono::steady_clock::now();

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
        initialized= true;
        Log::Info("CanEngine initialized.");
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
        return window.IsKeyPressed(key);
    }

    bool Engine::IsKeyJustPressed(int key){
        return window.IsKeyJustPressed(key);
    }
}