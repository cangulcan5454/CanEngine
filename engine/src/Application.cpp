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
    engine.Run(
        [](float deltaTime)
        {
            // Şimdilik yapılacak bir işlem yok.
        }
    );
}
}