# CanEngine

CanEngine is a modular game engine being developed in modern C++ as a computer engineering graduation project.

## Goals

The project aims to explore and implement core game-engine systems including:

- Engine architecture
- Application and game loop
- Window and input management
- Real-time rendering
- Shader management
- Resource management
- Performance profiling

The v0.1 scope and daily milestones are defined in
[the development plan](docs/CANENGINE_V0.1_PLAN.md).

## Technology

- C++20
- CMake
- OpenGL
- GLFW
- GLAD
- GLM

Additional libraries will be introduced as the project develops.

## Project Structure

```text
CanEngine/
├── engine/
│   ├── include/
│   └── src/
├── sandbox/
│   └── src/
├── assets/
├── docs/
├── tests/
├── CMakeLists.txt
└── README.md
```

## Status

Day 2: Engine/Sandbox architecture is documented in
[the architecture guide](docs/ARCHITECTURE.md), including build instructions.
