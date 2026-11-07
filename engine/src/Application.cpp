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
        [&](float deltaTime)
        {
            if (engine.IsKeyPressed(GLFW_KEY_W))
            {
                Log::Info("W key is pressed!");
            }

            if (engine.IsKeyJustPressed(GLFW_KEY_E))
            {
                Log::Info("E key is just pressed!");
            }
        }
    );

    engine.Shutdown();
}
}