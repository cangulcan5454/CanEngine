#include <CanEngine/Engine.h>
#include <iostream>

int main()
{
    float playerX = 0.0f;
    float speed = 120.0f;
    CanEngine::Engine engine;
    engine.Run([&](float deltaTime){
        playerX += speed * deltaTime;
        std::cout << "PlayerX: " << playerX << '\n';
    });

    return 0;
}
