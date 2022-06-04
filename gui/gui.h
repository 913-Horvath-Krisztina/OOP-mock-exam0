#pragma once
#include <QWidget>
#include "Service.h"
#include "Observer.h"

namespace Ui {
class GUI;
}

class GUI : public QWidget, public Observer
{
    Q_OBJECT
private:
    Service& serv;

public:
    explicit GUI(Service& s, QWidget *parent = nullptr);
    ~GUI();
    void populate_list();
    void update() override;

private:
    Ui::GUI *ui;
};

