#ifndef SIMPLEWINDOW_H
#define SIMPLEWINDOW_H

#include <QMainWindow>
#include "simulation.h"
#include "canvas.h"

class SimpleWindow : public QWidget
{
    Q_OBJECT

public:
    SimpleWindow(QWidget *parent = nullptr);
    ~SimpleWindow();

    void AddNewButtonPressed();

private slots:
    void HandleReceivedData(LifeformType type, QPointF coord, int size, int hp, int max_hp);

private:
    Canvas * cnvMain;
};
#endif // SIMPLEWINDOW_H
