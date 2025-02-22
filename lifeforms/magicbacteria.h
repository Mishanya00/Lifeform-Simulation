#ifndef MAGICBACTERIA_H
#define MAGICBACTERIA_H

#include "bacteria.h"

class MagicBacteria : public Bacteria
{
public:
    MagicBacteria(float x, float y);

    virtual void Draw(QPainter & painter);

protected:
    virtual void Reproduce();
    virtual void Eat();


    int power_; // Determines effectives of light use

private:
};

#endif // MAGICBACTERIA_H
