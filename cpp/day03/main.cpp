#include "Character.h"

int main()
{
    Character player("Can", 100, 25, 1);
    Character boss("Dragon", 500, 80, 50);

    player.Attack(boss);

    player.Print();
    boss.Print();

    return 0;
}