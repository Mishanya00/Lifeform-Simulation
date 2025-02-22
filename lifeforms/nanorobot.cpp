#include "nanorobot.h"

NanoRobot::NanoRobot(float x, float y)
{
    name_ = "Killer";
    coord_ = QPoint(x, y);
    size_ = 4;
    maxHp_ = 1000;
    hp_ = 1000;
    damage_ = 1000;
}

void NanoRobot::Draw(QPainter &painter)
{
    painter.save();

    painter.translate(coord_);

    painter.rotate(0);

    painter.setBrush(Qt::black);
    painter.drawRect(coord_.x(), coord_.y(), size_, size_);

    painter.restore();
}
