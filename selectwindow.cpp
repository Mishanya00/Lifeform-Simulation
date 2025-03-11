#include "selectwindow.h"

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QRegularExpression>


SelectWindow::SelectWindow(QWidget *parent, std::unique_ptr<Simulation> sim)
    : QDialog{parent}
{
    this->setWindowTitle("Add new Lifeform");
    this->resize(420, 300);

    auto ltMain = new QVBoxLayout(this);

    cbLifeSelect = new QComboBox();
    ltMain->addWidget(cbLifeSelect);
    cbLifeSelect->addItem("Bacteria");
    cbLifeSelect->addItem("Photo Bacteria");
    cbLifeSelect->addItem("Magic Bacteria");
    cbLifeSelect->addItem("Virus");
    cbLifeSelect->addItem("Nanorobot");

    auto ltFirstLine = new QHBoxLayout();
    ltMain->addLayout(ltFirstLine);

    auto labelX = new QLabel("X: ", this);
    ltFirstLine->addWidget(labelX);

    leX = new QLineEdit();
    leX->setPlaceholderText("X coord...");
    ltFirstLine->addWidget(leX);

    auto labelY = new QLabel("Y: ", this);
    ltFirstLine->addWidget(labelY);

    leY = new QLineEdit();
    leY->setPlaceholderText("Y coord...");
    ltFirstLine->addWidget(leY);

    ltFirstLine->setStretch(0, 1);
    ltFirstLine->setStretch(1, 4);
    ltFirstLine->setStretch(2, 1);
    ltFirstLine->setStretch(3, 4);

    // SECOND LINE OF LINE EDIT

    auto ltSecondLine = new QHBoxLayout();
    ltMain->addLayout(ltSecondLine);

    auto labelSizeX = new QLabel("Size: ", this);
    ltSecondLine->addWidget(labelSizeX);

    leSize = new QLineEdit();
    leSize->setPlaceholderText("Size. . .");
    ltSecondLine->addWidget(leSize);

    ltSecondLine->setStretch(0, 1);
    ltSecondLine->setStretch(1, 8);

    auto ltThirdLine = new QHBoxLayout();
    ltMain->addLayout(ltThirdLine);

    auto labelHP = new QLabel("HP: ", this);
    ltThirdLine->addWidget(labelHP);

    leHP = new QLineEdit();
    leHP->setPlaceholderText("HP...");
    ltThirdLine->addWidget(leHP);

    auto labelMaxHp = new QLabel("Max HP: ", this);
    ltThirdLine->addWidget(labelMaxHp);

    leMaxHP = new QLineEdit();
    leMaxHP->setPlaceholderText("Max HP...");
    ltThirdLine->addWidget(leMaxHP);

    ltThirdLine->setStretch(0, 1);
    ltThirdLine->setStretch(1, 4);
    ltThirdLine->setStretch(2, 1);
    ltThirdLine->setStretch(3, 4);

    auto ltFourthLine = new QHBoxLayout();
    ltMain->addLayout(ltFourthLine);

    ltFourthLine->addStretch(4);

    auto btnCreateLifeform = new QPushButton("Add", this);
    ltFourthLine->addWidget(btnCreateLifeform);
    ltFourthLine->setStretch(1, 2);
    connect(btnCreateLifeform, &QPushButton::clicked, this, [this, &sim]() { SelectWindow::AddButtonPressed(sim); });

    ltFourthLine->addStretch(4);
}

bool SelectWindow::isNumber(const QString &text) {
    QRegularExpression regExp("^-?\\d+$"); // Same regex as before
    return regExp.match(text).hasMatch(); // Check if the input matches the regex
}

void SelectWindow::AddButtonPressed(std::unique_ptr<Simulation>& sim)
{
    int x, y;
    int size;
    int hp, max_hp;
    bool isCorrect = true;

    if (isNumber(leX->text()) && isNumber(leY->text())) {
        x = leX->text().toInt();
        y = leX->text().toInt();
    }
    else {
        isCorrect = false;
        QMessageBox::critical(this, "Error", "Coordinate parameters contain non-integers");
    }
    if (isNumber(leHP->text()) && isNumber(leMaxHP->text())) {
        hp = leHP->text().toInt();
        max_hp = leMaxHP->text().toInt();
    }
    else {
        isCorrect = false;
        QMessageBox::critical(this, "Error", "Health parameters contain non-integers");
    }
    if (isNumber(leSize->text())) {
        size = leSize->text().toInt();
    }
    else {
        isCorrect = false;
        QMessageBox::critical(this, "Error", "Size parameters contain non-integers");
    }

    if (sim)
    {
    }
    this->deleteLater();
}
