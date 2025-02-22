#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QColor>

#include <memory>

#include "simulation.h"

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);
    void IterateButtonPressed();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    std::unique_ptr<Simulation> sims;

signals:
};

#endif // CANVAS_H
