#include "virus.h"

Virus::Virus(float x, float y)
{
    name_ = "Virus";
    coord_ = QPoint(x, y);
    size_ = 3;
    maxHp_ = 5;
    hp_ = 5;
    hunger_ = 25;
    damage_ = 2;
}

void Virus::Draw(QPainter &painter)
{
    painter.save();

    painter.translate(coord_);

    painter.rotate(0);

    painter.setBrush(Qt::red);
    painter.drawEllipse(QPointF(0, 0), size_, size_);

    painter.restore();
}

void Virus::Eat()
{

}
