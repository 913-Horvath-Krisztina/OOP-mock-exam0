#include <QApplication>
#include <QPushButton>
#include "gui.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Repository repo;
    Service serv = Service(repo);

    std::vector<GUI*> guis;

    for(auto u:repo.get_users()){
        GUI* g = new GUI{serv};
        guis.push_back(g);
        std::string title = u.get_name() + " " + u.get_type();
        g->setWindowTitle(title.c_str());

        g->show();
        g->resize(600, 400);
    }

    QApplication::exec();

    for(auto g: guis)
        delete g;
}
