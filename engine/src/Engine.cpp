#include <CanEngine/Engine.h>
#include <chrono>
#include <iostream>

namespace CanEngine
{
    void Engine::Run(std::function<void(float)> onUpdate)
    {
        std::cout << "CanEngine initialized." << std::endl;
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

            std::cout << "Frame: " << frame
                      << " | DeltaTime: " << deltaTime << '\n';

            if (frame >= 10)
            {
                running = false;
            }
        }
    }
}