#ifndef SIMULATION_H
#define SIMULATION_H

#include <QPainter>
//#include <vector>
#include <memory>
#include "lifeform.h"
#include "bacteria.h"
#include "lifeformcollection.h"

enum LifeformType {
    ltBacteria,
    ltMagicBacteria,
    ltPhotoBacteria,
    ltVirus,
    ltNanorobot,
};

class Simulation
{
public:
    Simulation(float width, float height);

    void Draw(QPainter & painter);

    void AddNewAgent(LifeformType type, QPoint coord, int size, int hp, int max_hp);

private:
    const float margin_ = 50.0;
    float width_, height_;
    //std::vector<std::unique_ptr<LifeForm>> agents_;
    LifeFormCollection agents_;
    std::unique_ptr<Bacteria> bact;
};

#endif // SIMULATION_H
