#include "Character.h"
#include <iostream>

Character::Character(
    std::string name,
    int maxHealth,
    int damage,
    int level
)
    : name(name),
      health(maxHealth),
      maxHealth(maxHealth),
      damage(damage),
      level(level)
{
}

void Character::SetHealth(int newHealth)
{
    if (newHealth < 0)
    {
        health = 0;
    }
    else if (newHealth > maxHealth)
    {
        health = maxHealth;
    }
    else
    {
        health = newHealth;
    }
}

int Character::GetHealth() const
{
    return health;
}

std::string Character::GetName() const
{
    return name;
}

int Character::GetDamage() const
{
    return damage;
}

int Character::GetLevel() const
{
    return level;
}

bool Character::IsAlive() const
{
    return health > 0;
}

void Character::TakeDamage(int damage)
{
    health -= damage;

    if (health < 0)
    {
        health = 0;
    }
}

void Character::Heal(int amount)
{
    health += amount;

    if (health > maxHealth)
    {
        health = maxHealth;
    }
}

void Character::Attack(Character& target) const
{
    target.TakeDamage(damage);
}

void Character::Print() const
{
    std::cout << "=== CHARACTER ===" << '\n';
    std::cout << "Name: " << name << '\n';
    std::cout << "Level: " << level << '\n';
    std::cout << "Health: " << health << '/' << maxHealth << '\n';
    std::cout << "Damage: " << damage << '\n';

    if (IsAlive())
    {
        std::cout << "Alive" << '\n';
    }
    else
    {
        std::cout << "Dead" << '\n';
    }
}