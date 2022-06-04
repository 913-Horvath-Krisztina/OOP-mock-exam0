#pragma once
#include "Issue.h"
#include "User.h"
#include "Subject.h"

class Repository: public Subject{
private:
    std::vector<User> users;
    std::vector<Issue> issues;

public:
    Repository();
    ~Repository();

    void read_file_users();
    void read_file_issues();
    void write_file_issues();

    std::vector<Issue> get_issues(){return issues; }
    std::vector<User> get_users() {return  users;}

    void add_issue(Issue i);

};
