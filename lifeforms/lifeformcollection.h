#ifndef LIFEFORMCOLLECTION_H
#define LIFEFORMCOLLECTION_H

#include <vector>
#include <memory>
#include "lifeform.h"
#include "bacteria.h"
#include "photobacteria.h"
#include "magicbacteria.h"
#include "virus.h"
#include "nanorobot.h"

enum LifeformType {
    ltBacteria,
    ltMagicBacteria,
    ltPhotoBacteria,
    ltVirus,
    ltNanorobot,
};

class LifeFormCollection
{
public:
    LifeFormCollection();

    /*
    template<typename T>
    void add(T &&entity)
    {
        agents_.emplace_back(std::make_unique<T>(std::move(entity)));
        //agents_.emplace_back(std::make_unique<T>(std::forward<T>(entity))); // тонкий момент
    }*/

    void add(LifeformType type, float x, float y) {
        switch (type)
        {
        case ltBacteria:
            agents_.emplace_back(std::make_unique<Bacteria>(x, y));
            break;
        case ltPhotoBacteria:
            agents_.emplace_back(std::make_unique<PhotoBacteria>(x, y));
            break;
        case ltMagicBacteria:
            agents_.emplace_back(std::make_unique<MagicBacteria>(x, y));
            break;
        case ltVirus:
            agents_.emplace_back(std::make_unique<Virus>(x, y));
            break;
        case ltNanorobot:
            agents_.emplace_back(std::make_unique<NanoRobot>(x, y));
            break;
        }
    }

    void del(size_t index);

    size_t size();

    std::unique_ptr<LifeForm>& operator[](size_t index);

private:
    std::vector<std::unique_ptr<LifeForm>> agents_;
};

#endif // LIFEFORMCOLLECTION_H
