#ifndef NANOROBOT_H
#define NANOROBOT_H

#include "lifeform.h"

class NanoRobot : public LifeForm // Perfect form of life... or not?
{
public:

    NanoRobot(float x, float y);

    void Draw(QPainter & painter) override;

protected:
    int damage_;
};

#endif // NANOROBOT_H
