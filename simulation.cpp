#include "simulation.h"

#include "random.h"


Simulation::Simulation(float width, float height)
{
    width_ = width;
    height_ = height;

    for (int i = 0; i < 10; ++i) {
        agents_.add(ltBacteria, rnd::RandFloat(margin_, width_-margin_), rnd::RandFloat(margin_, height_-margin_));
    }
    for (int i = 0; i < 5; ++i) {
        agents_.add(ltPhotoBacteria, rnd::RandFloat(margin_, width_-margin_), rnd::RandFloat(margin_, height_-margin_));
    }

    for (int i = 0; i < 3; ++i) {
        agents_.add(ltMagicBacteria, rnd::RandFloat(margin_, width_-margin_), rnd::RandFloat(margin_, height_-margin_));
    }

    for (int i = 0; i < 20; ++i) {
        agents_.add(ltVirus, rnd::RandFloat(margin_, width_-margin_), rnd::RandFloat(margin_, height_-margin_));
    }

    for (int i = 0; i < 20; ++i) {
        agents_.add(ltNanorobot, rnd::RandFloat(margin_, width_-margin_), rnd::RandFloat(margin_, height_-margin_));
    }
}

void Simulation::Draw(QPainter &painter)
{
    for (int i = 0; i < agents_.size(); ++i) {
        agents_[i]->Draw(painter);
    }
}

void Simulation::AddNewAgent(LifeformType type, QPointF coord, int size, int hp, int max_hp)
{
    agents_.add(type, coord.x(), coord.y());
    agents_[agents_.size()-1]->SetMaxHp(max_hp);
    agents_[agents_.size()-1]->SetHP(hp);
    agents_[agents_.size()-1]->SetSize(size);
}
