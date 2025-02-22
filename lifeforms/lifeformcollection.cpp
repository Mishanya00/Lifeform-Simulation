#include "lifeformcollection.h"

LifeFormCollection::LifeFormCollection() {}

void LifeFormCollection::del(size_t index)
{
    agents_.erase(agents_.begin() + index);
}

std::unique_ptr<LifeForm>& LifeFormCollection::operator[](size_t index)
{
    return agents_[index];
}

size_t LifeFormCollection::size() {
    return agents_.size();
}
