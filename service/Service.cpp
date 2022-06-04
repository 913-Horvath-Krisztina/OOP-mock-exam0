//
// Created by krisz on 6/4/2022.
//

#include "Service.h"

Service::~Service() {

}

void Service::add_issue_serv(std::string desc, std::string status, std::string reporter, std::string solver) {
    Issue i(desc, status, reporter, solver);
    this->repo.add_issue(i);
}
