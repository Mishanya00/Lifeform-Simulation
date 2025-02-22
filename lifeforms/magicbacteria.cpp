#include "magicbacteria.h"

MagicBacteria::MagicBacteria(float x, float y)
{
    name_ = "Vermillion De Servante Mono de Crystella";
    coord_ = QPoint(x, y);
    size_ = 5;
    maxHp_ = 100;
    hp_ = 100;
    hunger_ = 100;
}

void MagicBacteria::Draw(QPainter &painter)
{
    painter.save();

    painter.translate(coord_);

    painter.rotate(0);

    painter.setBrush(Qt::blue);
    painter.drawEllipse(QPointF(0, 0), 3 * size_, 1 * size_);

    painter.setBrush(Qt::cyan);
    painter.drawEllipse(QPointF(0, 0), size_, size_);

    painter.restore();
}

void MagicBacteria::Reproduce()
{

}

void MagicBacteria::Eat()
{

}
