#include "canvas.h"

#include <QPainter>

Canvas::Canvas(QWidget *parent)
    : QWidget{parent}
{
    this->resize(1100, 720);
    sims = std::make_unique<Simulation>(this->size().width(), this->size().height());
}

void Canvas::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);
    sims->Draw(painter);
}
void Canvas::IterateButtonPressed() {
    this->repaint();
}
