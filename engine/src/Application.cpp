#include <CanEngine/Application.h>
#include <CanEngine/Log.h>
#include <GLFW/glfw3.h>
#include <string>


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

            double mouseX;
            double mouseY;
            
            engine.GetMousePosition(mouseX,mouseY);

            if(engine.IsMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
            {
                Log::Info("Left click is pressed");
                Log::Info("mouseX = " + std::to_string(mouseX) + "mouseY = " + std::to_string(mouseY));
            }
         
        }
    );

    engine.Shutdown();
}
}