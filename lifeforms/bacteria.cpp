#include "bacteria.h"

#include "random.h"

Bacteria::Bacteria(float x, float y)
{
    name_ = "Bacteria";
    coord_ = QPoint(x, y);
    size_ = rnd::Randint(10,13);
    maxHp_ = 10;
    hp_ = 10;
    hunger_ = 100;
}

void Bacteria::Draw(QPainter &painter)
{
    //painter.setBrush(Qt::green);
    //painter.drawEllipse(coord_.x(), coord_.y(), 2 * size_, size_);

    painter.save();

    painter.translate(coord_);

    painter.rotate(45); // implement in future when there will be movement vector

    painter.setBrush(Qt::gray);
    painter.drawEllipse(QPointF(0, 0), 2 * size_, size_);

    painter.restore();
}

void Bacteria::Reproduce()
{
    // In Future
}

void Bacteria::Eat()
{

}
