#include <CanEngine/Application.h>
#include <CanEngine/Log.h>


namespace CanEngine
{
   void Application::Start()
   {
        Log::Info("Application started");
   }

   void Application::Run()
{
    if (!engine.Initialize())
{
    Log::Error("Engine initialization failed!");
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