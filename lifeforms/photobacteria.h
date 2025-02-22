#ifndef PHOTOBACTERIA_H
#define PHOTOBACTERIA_H

#include "bacteria.h"

class PhotoBacteria : public Bacteria
{
public:
    PhotoBacteria(float x, float y);

    void Draw(QPainter & painter) override;

protected:
    PhotoBacteria() {} // for future descendants

    virtual void Reproduce() override;
    virtual void Eat() override;


    int power_; // Determines effectives of light use
};

#endif // PHOTOBACTERIA_H
