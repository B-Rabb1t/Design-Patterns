#include <iostream>
#include <string>

using std::cout;
using std::string;

class Zombie
{
private:
    string intension;
    string behavior;
    string attackTechnique;
    string eatingHabits;

public:
    void attack()
    {
        cout << "A Zombie has attacked\n";
    }
};

class ArmyMan
{
private:
    string uniform;
    string weapon;
    string intension;
    string attackTechnique;

public:
    void attack()
    {
        cout << "An Army man has attached\n";
    }

    void chooseWeapon()
    {
        cout << "Army man is choosing a weapon\n";
    }
};

class Bullet
{
public:
    string color;
    unsigned int size;
    unsigned int imageSprite[5120]; // Placeholder memory for image sprite
    unsigned int speed;
    double coordinates;

    void loadBullet()
    {
        cout << "Bullet has been loaded\n";
    }

    void fireBullet()
    {
        cout << "Bullet has been fired\n";
    }
};

int main(void)
{
    Zombie zombieObj;
    ArmyMan armymanObj;
    Bullet bulletObj[100];

    cout << "***************************************\n";
    cout << "Loading Zombie application\n";
    cout << "***************************************\n\n";

    cout << "sizeof_zombieObj = " << sizeof(zombieObj) << " bytes\n"
         << "sizeof_armymanObj = " << sizeof(armymanObj) << " bytes\n"
         << "sizeof_bulletObj = " << sizeof(bulletObj) << " bytes";
}