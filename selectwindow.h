#ifndef SELECTWINDOW_H
#define SELECTWINDOW_H

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <memory>
#include "simulation.h"

class SelectWindow : public QDialog
{
    Q_OBJECT
public:
    explicit SelectWindow(QWidget *parent = nullptr, std::unique_ptr<Simulation> sim = nullptr);
    void AddButtonPressed(std::unique_ptr<Simulation>& sim);
    bool isNumber(const QString &text);

private:
    QLineEdit * leSize;
    QLineEdit * leX;
    QLineEdit * leY;
    QLineEdit * leHP;
    QLineEdit * leMaxHP;
    QComboBox * cbLifeSelect;

signals:

};

#endif // SELECTWINDOW_H
