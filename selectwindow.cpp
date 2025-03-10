#include "selectwindow.h"

#include <QComboBox>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

enum LifeformType {
    ltBacteria,
    ltMagicBacteria,
    ltPhotoBacteria,
    ltVirus,
    ltNanorobot,
};

SelectWindow::SelectWindow(QWidget *parent)
    : QDialog{parent}
{
    this->setWindowTitle("Add new Lifeform");
    this->resize(420, 300);

    auto ltMain = new QVBoxLayout(this);

    auto cbCypherSelect = new QComboBox();
    ltMain->addWidget(cbCypherSelect);
    cbCypherSelect->addItem("Bacteria");
    cbCypherSelect->addItem("Photo Bacteria");
    cbCypherSelect->addItem("Magic Bacteria");
    cbCypherSelect->addItem("Virus");
    cbCypherSelect->addItem("Nanorobot");

    auto ltFirstLine = new QHBoxLayout();
    ltMain->addLayout(ltFirstLine);

    auto labelX = new QLabel("X: ", this);
    ltFirstLine->addWidget(labelX);

    auto leX = new QLineEdit();
    leX->setPlaceholderText("X coord");
    ltFirstLine->addWidget(leX);

    auto labelY = new QLabel("Y: ", this);
    ltFirstLine->addWidget(labelY);

    auto leY = new QLineEdit();
    leY->setPlaceholderText("Y coord");
    ltFirstLine->addWidget(leY);
}
