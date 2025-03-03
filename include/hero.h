#ifndef HERO_H
#define HERO_H
#include "weapon.h"
class Hero
{
private:
    std::string _name;
    int _health;
    int _maxHealth;
    int _energy;
    int _maxEnergy;
    int _defoltDamage;
    Weapon* _weapon = nullptr;
public:
    Hero(std::string, int, int, int);
    virtual ~Hero(); /*YEs, virtual destructer...наследованные классы нужно очищать, ибо сами выделяем память*/
    void attackWithWeapon(Hero&);
    virtual void specialAbility(Hero&);
    void equipWeapon(Weapon*);
    void TakeDamage(int);
    void heal(int);
    void restoreEnergy(int);
    void spendEnergy(int);
    bool isAlive();
    int getHealth();
    int getEnergy();
    std::string getName();
};

#endif