#include <CanEngine/Application.h>
#include <iostream>

namespace CanEngine
{
   void Application::Start()
   {
        std::cout<< "Application started"<<'\n';
   }

   void Application::Run()
{
    if (!engine.Initialize())
{
    std::cerr << "Engine initialization failed!" << '\n';
    return;
}
    engine.Run(
        [](float deltaTime)
        {
            // Şimdilik yapılacak bir işlem yok.
        }
    );

    engine.Shutdown();
}
}