find_package(glfw3 3.5 CONFIG REQUIRED)

add_library(CanEngine STATIC
    src/Engine.cpp
    src/Application.cpp
    src/Log.cpp
    src/Window.cpp
    src/Input.cpp
    include/CanEngine/Engine.h
    include/CanEngine/Application.h
    include/CanEngine/Log.h
    include/CanEngine/Window.h
    include/CanEngine/Input.h
)

target_link_libraries(CanEngine
    PUBLIC
        glfw
)

target_compile_features(CanEngine PUBLIC cxx_std_20)

target_include_directories(CanEngine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
