#ifndef BACTERIA_H
#define BACTERIA_H

#include "lifeform.h"

class Bacteria : public LifeForm
{
public:
    Bacteria(float x, float y);
    virtual ~Bacteria() {}
    // As far as I know its not necessary to specify virtual if its virtual in the base class
    virtual void Draw(QPainter & painter) override;
    virtual void Reproduce();
    virtual void Eat();

protected:
    Bacteria() {} // for future descendants

    int hunger_;
};

#endif // BACTERIA_H
