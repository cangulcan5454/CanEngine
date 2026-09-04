#include <iostream>

int main()
{
    int health = 100;
    float speed = 4.5f;
    double position = 123.456789;
    char rank = 'A';
    bool alive = true;

    std::cout << "Health: " << health << '\n';
    std::cout << "Speed: " << speed << '\n';
    std::cout << "Position: " << position << '\n';
    std::cout << "Rank: " << rank << '\n';
    std::cout << "Alive: " << alive << '\n';

    std::cout << "\nMemory sizes:\n";
    std::cout << "int: " << sizeof(int) << " bytes\n";
    std::cout << "float: " << sizeof(float) << " bytes\n";
    std::cout << "double: " << sizeof(double) << " bytes\n";
    std::cout << "char: " << sizeof(char) << " bytes\n";
    std::cout << "bool: " << sizeof(bool) << " bytes\n";
    std::cout << "\nAddresses:\n";
    std::cout << "health address: " << &health << '\n';
    std::cout << "speed address: " << &speed << '\n';
    std::cout << "position address: " << &position << '\n';

    return 0;
}