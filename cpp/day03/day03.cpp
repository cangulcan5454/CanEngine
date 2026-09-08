#include <iostream>

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
    )
        :name(name),
        health(maxHealth),
        maxHealth(maxHealth),
        damage(damage),
        level(level)

        {

        }
    void SetHealth(int newHealth)
    {
        if (newHealth< 0)
        {
            health = 0;
        }
        else if (newHealth > maxHealth)
        {
            health= maxHealth;
        }
        else
        {
            health = newHealth;
        }
        
    }

    int GetHealth() const
    {
            return health;
    }

    std::string GetName() const
    {
        return name;
    }

    int GetDamage() const
    {
        return damage;
    }

    int GetLevel() const
    {
        return level;
    }

    bool IsAlive() const
    {
        return health > 0;
    }

    void TakeDamage(int damage)
    {
        health -= damage;

        if (health < 0)
        {
            health = 0;
        }
    }
    void Heal(int amount)
    {
        health += amount;

        if (health > maxHealth)
        {
            health = maxHealth;
        }
    }
    void Attack(Character& target) const
    {
        target.TakeDamage(damage);
    }
    void Print() const
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
};

int main()
{
    Character player("Can", 100, 25, 1);
    Character boss("Dragon", 500, 80, 50);

    player.Attack(boss);
    player.Print();
    boss.Print();
 return 0;
}