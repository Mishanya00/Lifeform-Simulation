#include "photobacteria.h"

PhotoBacteria::PhotoBacteria(float x, float y)
{
    name_ = "PhotoBacteria";
    coord_ = QPoint(x, y);
    size_ = rnd::Randint(15,17);
    maxHp_ = 50;
    hp_ = 50;
    hunger_ = 300;
}

void PhotoBacteria::Draw(QPainter &painter)
{
    painter.save();

    painter.translate(coord_);

    painter.rotate(0);

    painter.setBrush(Qt::green);
    painter.drawEllipse(QPointF(0, 0), 2 * size_, size_);

    painter.restore();
}

void PhotoBacteria::Reproduce()
{

}

void PhotoBacteria::Eat()
{

}
