#include "gui.h"
#include "ui_gui.h"

GUI::GUI(Service& s, QWidget *parent) :
    QWidget(parent), serv(s),
    ui(new Ui::GUI)
{
    ui->setupUi(this);
    populate_list();

}

GUI::~GUI()
{
    delete ui;
}

void GUI::populate_list() {
    ui->listWidget->clear();
    std::vector<Issue> issues = serv.get_sorted_issues();
    for(auto i:issues){
        QListWidgetItem* item = new QListWidgetItem(i.to_string().c_str());
        ui->listWidget->addItem(item);
    }
}

void GUI::update() {
    populate_list();
}
