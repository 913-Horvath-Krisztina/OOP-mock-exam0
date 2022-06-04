//
// Created by krisz on 6/4/2022.
//

#include "Service.h"
#include <algorithm>

Service::~Service() {

}

void Service::add_issue_serv(std::string desc, std::string status, std::string reporter, std::string solver) {
    Issue i(desc, status, reporter, solver);
    this->repo.add_issue(i);
}

std::vector<Issue> Service::get_sorted_issues() {
    std::vector<Issue> sorted = repo.get_issues();

    std::sort(sorted.begin(), sorted.end(), [](Issue i1, Issue i2){return i1.get_status() > i2.get_status();});

    std::sort(sorted.begin(), sorted.end(), [](Issue i1, Issue i2){if(i1.get_status() == "open" && i2.get_status() == "open") return i1.get_description() < i2.get_description(); return false;});
    std::sort(sorted.begin(), sorted.end(), [](Issue i1, Issue i2){if(i1.get_status() == "closed" && i2.get_status() == "closed") return i1.get_description() < i2.get_description(); return false;});

    return sorted;

}
