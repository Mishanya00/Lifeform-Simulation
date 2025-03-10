#ifndef SIMPLEWINDOW_H
#define SIMPLEWINDOW_H

#include <QMainWindow>

class SimpleWindow : public QWidget
{
    Q_OBJECT

public:
    SimpleWindow(QWidget *parent = nullptr);
    ~SimpleWindow();

    void AddNewButtonPressed();
};
#endif // SIMPLEWINDOW_H
