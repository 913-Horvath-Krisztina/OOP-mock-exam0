#include <QApplication>
#include <QPushButton>
#include "gui.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Service serv = Service();
    serv.read_file_issues();
    serv.read_from_users();

//    std::vector<GUI*> guis;


    for(auto u:serv.get_users()){

//        guis.push_back(g);
        GUI* g = new GUI{serv};
        std::string title = u.get_name() + " " + u.get_type();
        g->setWindowTitle(title.c_str());

        g->show();
        g->resize(600, 400);
    }

    return QApplication::exec();

//    for(auto g: guis)
//        delete g;
}
