
#include <iostream>

 void TakeDamage(int* playerHealth, int damage)
    {

        *playerHealth -=damage;
    }

int main(){

    const int maxPlayerHealth= 100;
    int playerHealth = 100;
    std::cout << "===PLAYER===" << '\n';
    std::cout << "MaxHealth: " << maxPlayerHealth<< '\n';
    std::cout << "Health: " << playerHealth << '\n';
    std::cout << "Damage: 25" << '\n'; 
    TakeDamage(&playerHealth, 25);
    std::cout << "Health: " << playerHealth << '\n';
    int* bossHealth = new int(500);
    std::cout << "===BOSS===" << '\n';
    std::cout << "Boss Health: "<< *bossHealth << '\n';
    std::cout << "Damage: 120" << '\n';
    TakeDamage(bossHealth,120);
    std::cout << "Boss Health: "<< *bossHealth << '\n';

    delete bossHealth;
    bossHealth = nullptr;

    return 0;
}
    