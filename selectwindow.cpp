#include "selectwindow.h"

#include <QComboBox>
#include <QPushButton>
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
    leX->setPlaceholderText("X coord...");
    ltFirstLine->addWidget(leX);

    auto labelY = new QLabel("Y: ", this);
    ltFirstLine->addWidget(labelY);

    auto leY = new QLineEdit();
    leY->setPlaceholderText("Y coord...");
    ltFirstLine->addWidget(leY);

    ltFirstLine->setStretch(0, 1);
    ltFirstLine->setStretch(1, 4);
    ltFirstLine->setStretch(2, 1);
    ltFirstLine->setStretch(3, 4);

    // SECOND LINE OF LINE EDIT

    auto ltSecondLine = new QHBoxLayout();
    ltMain->addLayout(ltSecondLine);

    auto labelSizeX = new QLabel("Size X: ", this);
    ltSecondLine->addWidget(labelSizeX);

    auto leSizeX = new QLineEdit();
    leSizeX->setPlaceholderText("Size x...");
    ltSecondLine->addWidget(leSizeX);

    auto labelSizeY = new QLabel("Size Y: ", this);
    ltSecondLine->addWidget(labelSizeY);

    auto leSizeY = new QLineEdit();
    leSizeY->setPlaceholderText("Size y...");
    ltSecondLine->addWidget(leSizeY);

    ltSecondLine->setStretch(0, 1);
    ltSecondLine->setStretch(1, 4);
    ltSecondLine->setStretch(2, 1);
    ltSecondLine->setStretch(3, 4);

    auto ltThirdLine = new QHBoxLayout();
    ltMain->addLayout(ltThirdLine);

    auto labelHP = new QLabel("HP: ", this);
    ltThirdLine->addWidget(labelHP);

    auto leHP = new QLineEdit();
    leHP->setPlaceholderText("HP...");
    ltThirdLine->addWidget(leHP);

    auto labelMaxHp = new QLabel("Max HP: ", this);
    ltThirdLine->addWidget(labelMaxHp);

    auto leMaxHP = new QLineEdit();
    leMaxHP->setPlaceholderText("Max HP...");
    ltThirdLine->addWidget(leMaxHP);

    ltThirdLine->setStretch(0, 1);
    ltThirdLine->setStretch(1, 4);
    ltThirdLine->setStretch(2, 1);
    ltThirdLine->setStretch(3, 4);

    auto ltFourthLine = new QHBoxLayout();
    ltMain->addLayout(ltFourthLine);

    ltFourthLine->addStretch(4);

    auto btnCreateLifeform = new QPushButton("open", this);
    ltFourthLine->addWidget(btnCreateLifeform);
    ltFourthLine->setStretch(1, 2);

    ltFourthLine->addStretch(4);
}
