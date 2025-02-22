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
        agents_.add(Bacteria(rnd::RandFloat(margin_, width_-margin_), rnd::RandFloat(margin_, height_-margin_)));
    }

    for (int i = 0; i < 5; ++i) {
        agents_.add(PhotoBacteria(rnd::RandFloat(margin_, width_-margin_), rnd::RandFloat(margin_, height_-margin_)));
    }

    for (int i = 0; i < 3; ++i) {
        agents_.add(MagicBacteria(rnd::RandFloat(margin_, width_-margin_), rnd::RandFloat(margin_, height_-margin_)));
    }

    for (int i = 0; i < 20; ++i) {
        agents_.add(Virus(rnd::RandFloat(margin_, width_-margin_), rnd::RandFloat(margin_, height_-margin_)));
    }

    for (int i = 0; i < 20; ++i) {
        agents_.add(NanoRobot(rnd::RandFloat(margin_, width_-margin_), rnd::RandFloat(margin_, height_-margin_)));
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
