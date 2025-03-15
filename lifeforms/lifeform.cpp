#include "lifeform.h"

LifeForm::LifeForm() {}

bool LifeForm::isAlive()
{
    return isAlive_;
}

std::string &LifeForm::name()
{
    return name_;
}

int LifeForm::maxHp()
{
    return maxHp_;
}

int LifeForm::hp()
{
    return hp_;
}

void LifeForm::SetMaxHp(int max_hp)
{
    maxHp_ = max_hp;
}

void LifeForm::SetHP(int hp)
{
    hp_ = hp;
}

void LifeForm::SetSize(int size)
{
    size_ = size;
}
