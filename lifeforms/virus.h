#ifndef VIRUS_H
#define VIRUS_H

#include "lifeform.h"

class Virus : public LifeForm
{
public:
    Virus(float x, float y);

    virtual void Draw(QPainter & painter) override;

    virtual void Eat();  // Its planned virus will reproduce only while eating

protected:
    int hunger_;
    int damage_;
};

#endif // VIRUS_H
