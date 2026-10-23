# CanEngine v0.1 Development Plan

## Main Goal

Deliver a complete and demonstrable CanEngine v0.1 by the end of the current semester.

The engine will be developed while learning the required C++ concepts directly through the project.

---

## v0.1 Scope

- [ ] C++20 + CMake
- [ ] Engine / Sandbox architecture
- [ ] Application
- [ ] Game Loop
- [ ] Delta Time
- [ ] Logging
- [ ] GLFW Window
- [ ] Keyboard Input
- [ ] Mouse Input
- [ ] OpenGL + GLAD
- [ ] Vertex Buffer
- [ ] Index Buffer
- [ ] Vertex Array
- [ ] Shader
- [ ] Texture
- [ ] Transform
- [ ] Camera
- [ ] FPS / Frame Time
- [ ] Demo Scene

---

## OUT OF SCOPE FOR v0.1

Do NOT add these before v0.1 is complete:

- ECS
- Physics Engine
- Collision System
- Editor
- Audio
- Animation
- Networking
- Vulkan
- Scene Serialization
- Advanced Lighting
- Shadow Mapping

These may be considered for v0.2/v1.0 if the graduation project is allowed to continue next semester.

---

## Development Rule

Before adding a new feature, ask:

> Is CanEngine v0.1 complete?

If NO: do not expand the scope.

---

## Roadmap

### Week 1 — Engine Core

- [x] Day 1 — CMake configure/build
- [ ] Day 2 — Engine/Sandbox architecture
- [ ] Day 3 — Application class
- [ ] Day 4 — Game Loop
- [ ] Day 5 — Delta Time

### Week 2 — Core Systems

- [ ] Day 6 — Engine lifecycle
- [ ] Day 7 — Logging
- [ ] Day 8 — GLFW integration
- [ ] Day 9 — Window abstraction
- [ ] Day 10 — Window lifecycle

### Week 3 — Input

- [ ] Day 11 — Keyboard input
- [ ] Day 12 — Mouse input
- [ ] Day 13 — Input module
- [ ] Day 14 — Events/callbacks
- [ ] Day 15 — Window/Input test

### Week 4 — OpenGL

- [ ] Day 16 — Rendering pipeline
- [ ] Day 17 — GLAD
- [ ] Day 18 — OpenGL context
- [ ] Day 19 — Clear screen
- [ ] Day 20 — First triangle

### Week 5 — Buffers

- [ ] Day 21 — Vertex structure
- [ ] Day 22 — Vertex Buffer
- [ ] Day 23 — Vertex Array
- [ ] Day 24 — Index Buffer
- [ ] Day 25 — Renderer abstraction

### Week 6 — Shaders

- [ ] Day 26 — GLSL
- [ ] Day 27 — Shader class
- [ ] Day 28 — Shader error handling
- [ ] Day 29 — Uniforms
- [ ] Day 30 — Colored object demo

### Week 7 — Textures

- [ ] Day 31 — Texture concepts
- [ ] Day 32 — Image loading
- [ ] Day 33 — Texture class
- [ ] Day 34 — Textured quad
- [ ] Day 35 — Multiple textures

### Week 8 — Transform & Camera

- [ ] Day 36 — Vector/Matrix fundamentals
- [ ] Day 37 — GLM
- [ ] Day 38 — Transform
- [ ] Day 39 — Model Matrix
- [ ] Day 40 — Camera

### Week 9 — v0.1 Completion

- [ ] Day 41 — View/Projection
- [ ] Day 42 — Delta-time camera movement
- [ ] Day 43 — Demo scene
- [ ] Day 44 — FPS / Frame Time
- [ ] Day 45 — Stabilization and final build

---

## Definition of Done — CanEngine v0.1

CanEngine v0.1 is complete when:

- Project builds cleanly with CMake.
- Sandbox uses the CanEngine library.
- A window can be created.
- Keyboard and mouse input work.
- OpenGL rendering works.
- Shaders are managed by CanEngine.
- Textures can be rendered.
- Objects support transforms.
- Camera movement works.
- FPS and frame time are measurable.
- A small demonstration scene is available.

---

## Working Agreement

This file is the single source of truth for CanEngine v0.1 scope and progress.

Before starting a new task:
1. Check this file.
2. Continue from the first unchecked day.
3. Do not add out-of-scope features before v0.1 is complete.
4. Mark completed milestones with `[x]`.
5. Commit roadmap updates together with the corresponding development work.
