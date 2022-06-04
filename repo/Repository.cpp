//
// Created by krisz on 6/4/2022.
//

#include "Repository.h"
#include <fstream>

Repository::Repository() {

}

Repository::~Repository() {

}

void Repository::read_file_users() {
    std::string file = R"(C:\Facultate\OOP\tests\OOP-mock-exam0\repo\users.txt)";
    std::ifstream f(file);

    User u{};
    while(f >> u){
        users.push_back(u);
    }
    f.close();

}

void Repository::read_file_issues() {
    std::string file = R"(C:\Facultate\OOP\tests\OOP-mock-exam0\repo\issues.txt)";
    std::ifstream f(file);

    Issue i{};
    while(f >> i)
        issues.push_back(i);
    f.close();
}

void Repository::write_file_issues() {
    std::string file = R"(C:\Facultate\OOP\tests\OOP-mock-exam0\repo\issues.txt)";
    std::ofstream f(file, std::ios::trunc);
    if(!f.is_open()){
        std::string error = "\n\tError! Couldn't open watchlist CSV file!\n";
        return;
    }
    for(auto m: issues)
        f << m << "\n";
    f.close();

}

void Repository::add_issue(Issue i) {
    issues.push_back(i);
    notify(); /// observer notify
}
