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

        bool running = true;
        int frame = 0;

        auto previousTime = std::chrono::steady_clock::now();

        while (running)
        {
            auto currentTime = std::chrono::steady_clock::now();

            std::chrono::duration<float> elapsed =
                currentTime - previousTime;

            float deltaTime = elapsed.count();
            previousTime = currentTime;

            if (onUpdate){
            onUpdate(deltaTime);}
            frame++;

            Log::Info("Frame: "+ std::to_string(frame) + " | DeltaTime: " + std::to_string(deltaTime));

            if (frame >= 10)
            {
                running = false;
            }
        }
    }
    bool Engine::Initialize(){

        if (initialized){
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

        initialized=false;
        Log::Info("CanEngine shutdown.");
    }
}