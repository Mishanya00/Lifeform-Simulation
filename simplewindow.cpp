#include "simplewindow.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "canvas.h"
#include "random.h"
#include "selectwindow.h"

#include <iostream>

void SimpleWindow::AddNewButtonPressed()
{
    SelectWindow *secondWindow = new SelectWindow(this);
    connect(secondWindow, &SelectWindow::DataReceived, this, &SimpleWindow::HandleReceivedData);
    secondWindow->setAttribute(Qt::WA_DeleteOnClose); // Automatically delete the window when closed
    secondWindow->show();
}

void SimpleWindow::HandleReceivedData(LifeformType type, QPointF coord, int size, int hp, int max_hp)
{
    std::cout << "Got data!\n";
    std::cout << size << ' ' << hp << ' ' << max_hp << '\n';
    cnvMain->sims->AddNewAgent(type, coord, size, hp, max_hp);
    cnvMain->update();
}

SimpleWindow::SimpleWindow(QWidget *parent)
    : QWidget(parent)
{
    rnd::Init();

    this->resize(1280, 720);

    auto outer = new QHBoxLayout(this);

    cnvMain = new Canvas(this);
    outer->addWidget(cnvMain);
    outer->setStretch(0, 9);

    auto inner = new QVBoxLayout;
    outer->addLayout(inner);
    outer->setStretch(1, 1);

    auto btnIterate = new QPushButton("Iterate", this);
    connect(btnIterate, &QPushButton::clicked, cnvMain, &Canvas::IterateButtonPressed);
    inner->addWidget(btnIterate);

    auto btnAddLife = new QPushButton("Add Lifeform", this);
    connect(btnAddLife, &QPushButton::clicked, this, &SimpleWindow::AddNewButtonPressed);
    inner->addWidget(btnAddLife);

    //inner->setStretch(0, 1);
    //inner->setStretch(1, 9);
    inner->addStretch();
}

SimpleWindow::~SimpleWindow() {}
