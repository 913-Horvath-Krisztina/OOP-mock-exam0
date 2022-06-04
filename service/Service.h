#pragma once
#include "Repository.h"
//#include "gui.h"

class Service{
private:
    Repository& repo;

public:
    Service(Repository& r): repo(r) {repo.read_file_issues(); repo.read_file_users();}
    ~Service();

    std::vector<Issue> get_issues_serv() { return repo.get_issues(); }
    int add_issue_serv(std::string desc, std::string status, std::string reporter, std::string solver);

    std::vector<Issue> get_sorted_issues();

//    void record_observer(GUI* g);
};
