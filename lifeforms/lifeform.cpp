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
