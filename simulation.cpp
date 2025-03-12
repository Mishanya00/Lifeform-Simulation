#include "simulation.h"

#include "random.h"

#include "bacteria.h"
#include "photobacteria.h"
#include "magicbacteria.h"
#include "virus.h"
#include "nanorobot.h"


Simulation::Simulation(float width, float height)
{
    width_ = width;
    height_ = height;

    for (int i = 0; i < 10; ++i) {
        agents_.add(std::make_unique<Bacteria>(rnd::RandFloat(margin_, width_-margin_), rnd::RandFloat(margin_, height_-margin_)));    }

    for (int i = 0; i < 5; ++i) {
        agents_.add(std::make_unique<PhotoBacteria>(rnd::RandFloat(margin_, width_-margin_), rnd::RandFloat(margin_, height_-margin_)));    }

    for (int i = 0; i < 3; ++i) {
        agents_.add(std::make_unique<MagicBacteria>(rnd::RandFloat(margin_, width_-margin_), rnd::RandFloat(margin_, height_-margin_)));    }

    for (int i = 0; i < 20; ++i) {
        agents_.add(std::make_unique<Virus>(rnd::RandFloat(margin_, width_-margin_), rnd::RandFloat(margin_, height_-margin_)));    }

    for (int i = 0; i < 20; ++i) {
        agents_.add(std::make_unique<NanoRobot>(rnd::RandFloat(margin_, width_-margin_), rnd::RandFloat(margin_, height_-margin_)));
    }
}

void Simulation::Draw(QPainter &painter)
{
    for (int i = 0; i < agents_.size(); ++i) {
        agents_[i]->Draw(painter);
    }

    Bacteria * bact = new PhotoBacteria(100, 100);
    bact->Draw(painter);

}

void Simulation::AddNewAgent(LifeformType type, QPoint coord, int size, int hp, int max_hp)
{
    std::unique_ptr<LifeForm> agent;

    switch (type)
    {
    case ltBacteria:
        agent = std::make_unique<Bacteria>(coord.x(), coord.y());
        agents_.add(std::move(agent));
        break;
    case ltMagicBacteria:
        agents_.add(std::make_unique<MagicBacteria>(coord.x(), coord.y()));
        break;
    case ltPhotoBacteria:
        agents_.add(std::make_unique<PhotoBacteria>(coord.x(), coord.y()));
        break;
    case ltVirus:
        agents_.add(std::make_unique<Virus>(coord.x(), coord.y()));
        break;
    case ltNanorobot:
        agents_.add(std::make_unique<NanoRobot>(coord.x(), coord.y()));
        break;
    }
}
