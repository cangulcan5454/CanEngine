#include <CanEngine/Log.h>
#include <string>
#include <iostream>

namespace CanEngine{
    void Log::Info(const std::string& message){
        std::cout << "[INFO] " << message << '\n';
    }
    void Log::Warning(const std::string& message){
        std::cout << "[WARNING] " << message << '\n';
    }
    void Log::Error(const std::string& message){
        std::cerr << "[ERROR] " << message << '\n';
    }
}