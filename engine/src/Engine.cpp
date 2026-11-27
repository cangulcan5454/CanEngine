#include <CanEngine/Engine.h>
#include <CanEngine/Log.h>
#include <CanEngine/VertexBuffer.h>
#include <glad/gl.h>
#include <chrono>

namespace CanEngine
{
    Engine::Engine()
        :input(window)
    {
    }

    struct Vertex
    {
        float position[3];
    };

    Vertex vertices[3] ={
        {{0.0f,0.5f,0.0f}},
        {{-0.5f,-0.5f,0.0f}},
        {{0.5f,-0.5f,0.0f}}
    };


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
        unsigned int VAO;
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        
        VertexBuffer vertexbuffer(vertices, sizeof(vertices));

        glVertexAttribPointer(
            0,
            3,
            GL_FLOAT,
            GL_FALSE,
            sizeof(Vertex),
            (void*)offsetof(Vertex, position)
        );
        glEnableVertexAttribArray(0);

        const char* vertexShaderSource = R"(
        #version 330 core

        layout (location = 0) in vec3 aPos;

        void main()
        {
            gl_Position = vec4(aPos, 1.0);
        }
        )";
        const char* fragmentShaderSource = R"(
        #version 330 core

        out vec4 FragColor;

        void main()
        {
            FragColor = vec4(1.0, 0.5, 0.0, 1.0);
        }
        )";

        unsigned int vertexShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
        glCompileShader(vertexShader);
        int success;
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (success == GL_FALSE)
        {
            char infoLog[512];

            glGetShaderInfoLog(
                vertexShader,
                512,
                nullptr,
                infoLog
            );

            Log::Error(infoLog);
        }

        unsigned int fragmentShader;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (success == GL_FALSE)
        {
            char infoLog[512];

            glGetShaderInfoLog(
                fragmentShader,
                512,
                nullptr,
                infoLog
            );

            Log::Error(infoLog);
        }

        unsigned int shaderProgram;
        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (success == GL_FALSE)
        {
            char infoLog[512];

            glGetProgramInfoLog(
                shaderProgram,
                512,
                nullptr,
                infoLog
            );

            Log::Error(infoLog);
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        glUseProgram(shaderProgram);

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
            glBindVertexArray(VAO);
            glDrawArrays(GL_TRIANGLES, 0, 3);
            glfwSwapBuffers(window.GetNativeWindow());
            frame++;

        }
        glDeleteVertexArrays(1, &VAO);
        glDeleteProgram(shaderProgram);
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