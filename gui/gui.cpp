#include "gui.h"
#include "ui_gui.h"
#include <QMessageBox>

GUI::GUI(Service& s, QWidget *parent) :
    QWidget(parent), serv(s),
    ui(new Ui::GUI)
{
    ui->setupUi(this);
    connect_signals_slots();
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

void GUI::connect_signals_slots() {
    QObject::connect(ui->add_issue_pushButton, &QPushButton::clicked, this, &GUI::add_issue);
}

void GUI::add_issue() {
    std::string desc, status, reporter, solver;
    desc = ui->description_lineEdit->text().toStdString();
    status = ui->status_lineEdit->text().toStdString();
    reporter = ui->reporter_lineEdit->text().toStdString();
    solver = ui->solver_lineEdit->text().toStdString();

    if(serv.add_issue_serv(desc, status, reporter, solver) == 0){
        QMessageBox::critical(this, "Error", "Description error");
    }
    update();

}
