#pragma once

#include <string>

class Character
{
private:
    int health;
    int maxHealth;
    std::string name;
    int damage;
    int level;

public:
    Character(
        std::string name,
        int maxHealth,
        int damage,
        int level
    );

    void SetHealth(int newHealth);

    int GetHealth() const;
    std::string GetName() const;
    int GetDamage() const;
    int GetLevel() const;

    bool IsAlive() const;

    void TakeDamage(int damage);
    void Heal(int amount);
    void Attack(Character& target) const;

    void Print() const;
};