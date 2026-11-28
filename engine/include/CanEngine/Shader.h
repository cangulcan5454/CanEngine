#pragma once
#include <string>

namespace CanEngine{
    class Shader{
        public:
        Shader(const std::string& vertexPath, const std::string& fragmentPath);
        bool Initialize();
        void Use();
        void Shutdown();
        private:
        unsigned int shaderProgram = 0;

        std::string vertexPath;
        std::string fragmentPath;
    };
}