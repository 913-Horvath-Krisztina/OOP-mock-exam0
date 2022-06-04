#pragma once
#include "Repository.h"

class Service{
private:
    Repository& repo;

public:
    Service(Repository& r): repo(r) {repo.read_file_issues(); repo.read_file_users();}
    ~Service();

    std::vector<Issue> get_issues_serv() { return repo.get_issues(); }
    void add_issue_serv(std::string desc, std::string status, std::string reporter, std::string solver);
};
