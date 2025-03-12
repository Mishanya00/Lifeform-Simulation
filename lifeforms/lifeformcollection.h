#ifndef LIFEFORMCOLLECTION_H
#define LIFEFORMCOLLECTION_H

#include <vector>
#include <memory>
#include "lifeform.h"

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

    void add(std::unique_ptr<LifeForm> entity) {
        agents_.push_back(std::move(entity));
    }

    void del(size_t index);

    size_t size();

    std::unique_ptr<LifeForm>& operator[](size_t index);

private:
    std::vector<std::unique_ptr<LifeForm>> agents_;
};

#endif // LIFEFORMCOLLECTION_H
