#pragma once
#include <string>
#include <vector>
#include <sstream>

class Issue {
private:
    std::string description;
    std::string status;
    std::string reporter;
    std::string solver;

public:
    Issue();
    Issue(std::string d, std::string s, std::string r, std::string sol): description(d), status(s), reporter(r), solver(sol){}
    ~Issue();

    std::string to_string();
    friend std::istream& operator>>(std::istream& is, Issue& i);
    friend std::ostream& operator<<(std::ostream& is, Issue& i);

};



