# Daily Log

### 2026-09-05

**Today's Goal**
- Continue C++ fundamentals
- Learn references, const correctness, structs, enums and constructors
- Build a simple character combat system

**What I Learned**
- References (`&`)
- Const references (`const T&`)
- Structs
- `enum class`
- Constructors
- Member initializer lists
- Member functions
- Const member functions
- Basic object-oriented design

**What I Built**
- Character struct
- Player and Boss character types
- Health and damage system
- Heal and TakeDamage methods
- Attack method
- IsAlive method
- PrintCharacter method
- Simple turn-based combat loop

**Problems / Questions**
- Learned why `std::` is used
- Learned the difference between string and enum
- Learned why `enum class` is safer than plain enum
- Learned why `const` is placed after some member functions

**Git Commit**
- Day 2: character system and C++ fundamentals

**Tomorrow**
- Classes
- public / private
- Header and source files

### 2026-09-08

**Today's Goal**
- Learn the difference between structs and classes
- Understand public and private access
- Practice encapsulation
- Separate a C++ class into header and source files

**What I Learned**
- Difference between `struct` and `class`
- Default access levels in structs and classes
- `public` and `private`
- Encapsulation
- Getters and controlled setters
- Private member variables
- Const getter/member functions
- Class constructors with initializer lists
- Header files (`.h`)
- Source files (`.cpp`)
- `#pragma once`
- Scope resolution operator (`::`)
- Basic compiler vs linker distinction

**What I Built**
- Converted the Character struct into a Character class
- Made character data private
- Added GetHealth, GetName, GetDamage and GetLevel getters
- Added controlled SetHealth logic
- Added TakeDamage and Heal methods
- Added Attack and IsAlive methods
- Added Print method
- Split Character into:
  - Character.h
  - Character.cpp
  - main.cpp
- Compiled multiple source files together

**Problems / Questions**
- Learned why class members are private by default
- Learned why private data should be modified through controlled methods
- Learned why const member functions cannot modify the object
- Learned why function declarations are placed in header files and implementations in source files
- Learned why Character.cpp must be included during compilation

**Git Commit**
- Day 3: classes, encapsulation and header-source separation

**Tomorrow**
- Destructors
- RAII
- Object lifetime