#include "simplewindow.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "canvas.h"
#include "random.h"

SimpleWindow::SimpleWindow(QWidget *parent)
    : QWidget(parent)
{
    rnd::Init();

    this->resize(1280, 720);

    auto outer = new QHBoxLayout(this);

    auto cnvMain = new Canvas(this);
    outer->addWidget(cnvMain);
    outer->setStretch(0, 9);

    auto inner = new QVBoxLayout;
    outer->addLayout(inner);
    outer->setStretch(1, 1);

    auto btnIterate = new QPushButton("Iterate", this);
    connect(btnIterate, &QPushButton::clicked, cnvMain, &Canvas::IterateButtonPressed);
    inner->addWidget(btnIterate);

    //inner->setStretch(0, 1);
    //inner->setStretch(1, 9);
    inner->addStretch();
}

SimpleWindow::~SimpleWindow() {}
