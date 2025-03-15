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
    explicit SelectWindow(QWidget *parent = nullptr);
    void AddButtonPressed();
    bool isNumber(const QString &text);

private:
    QLineEdit * leSize;
    QLineEdit * leX;
    QLineEdit * leY;
    QLineEdit * leHP;
    QLineEdit * leMaxHP;
    QComboBox * cbLifeSelect;

signals:
    void DataReceived(LifeformType type, QPointF coord, int size, int hp, int max_hp);
};

#endif // SELECTWINDOW_H
