#ifndef LIFEFORM_H
#define LIFEFORM_H

#include <string>
#include <QPainter>
#include <QPointF>

#include "random.h" // to include it without saying to all descendants cause they 100% need it!

class LifeForm
{
public:
    LifeForm();

    bool isAlive();
    std::string & name();
    int maxHp();
    int hp();

    virtual void Draw(QPainter & painter) = 0;

    // necessary method in future for every inheritant to implement
    // virtual void onTick() = 0; // Some EnvironmentInfo variable will be passed here

protected:
    std::string name_;
    QPointF coord_;
    int maxHp_;
    int hp_;
    int size_;
    int speed_;
    bool isAlive_;
};

#endif // LIFEFORM_H
