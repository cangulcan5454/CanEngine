#include <iostream>
#include <string>

enum class CharacterType
{
    Player,
    Boss
};

struct Character
{
    std::string name;
    CharacterType type;
    int health;
    int maxHealth;
    int damage;
    int level;
    Character(
        std::string characterName,
        CharacterType characterType,
        int characterHealth,
        int characterDamage,
        int characterLevel
    )
    
        : name(characterName),
        type(characterType),
        health(characterHealth),
        maxHealth(characterHealth),
        damage(characterDamage),
        level(characterLevel)
    {
        
    }
    bool IsAlive() const
    {
        return health > 0;
    }   
    void Heal(int amount){
        health+=amount;
        if (health > maxHealth)
        health = maxHealth;
    }

    void TakeDamage(int damage){
        health -= damage;
        if (health<0)health=0;
    }

    void Attack(Character& target) const
    {
        target.TakeDamage(damage);
    }

    void PrintCharacter() const
    {
    if (type == CharacterType::Player)
    std::cout << "=== PLAYER ===" << '\n';
    else
    std::cout << "=== BOSS ===" << '\n';
    std::cout << "Name: " << name << '\n';
    std::cout <<" Level: "<<level<<'\n';
    std::cout << "Health: " << health << '/' << maxHealth << '\n';
    std::cout << "Damage: " << damage << '\n';
    if (IsAlive()) std::cout<< "Alive" <<'\n';
    else std::cout<< "Dead" <<'\n';
    
    }
};


int main()
{
    Character player("Can",CharacterType::Player,100,25,1);

    Character boss("Dragon",CharacterType::Boss,500,80,50);

    while(player.IsAlive() && boss.IsAlive()){
       std::cout << player.name << " attacks " << boss.name << '\n';
        player.Attack(boss);
        std::cout << boss.name << " Health: " << boss.health << '\n';
        if (!boss.IsAlive())break;
        std::cout << boss.name << " attacks " << player.name << '\n';
        boss.Attack(player);
        std::cout << player.name << " Health: " << player.health << '\n';
    }
    if (player.IsAlive()){
        std::cout<<"Can wins"<<'\n';
    }
    else{
        std::cout<<"Dragon wins"<<'\n';
    }
    player.PrintCharacter();
    boss.PrintCharacter();
    return 0;
}