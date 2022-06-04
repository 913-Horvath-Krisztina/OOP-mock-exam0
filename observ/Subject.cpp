//
// Created by krisz on 6/4/2022.
//

#include "Subject.h"
#include <algorithm>

void Subject::removeObserver(Observer *o) {
    auto it = std::find(observers.begin(), observers.end(), o);
    if(it != observers.end())
        observers.erase(it);
}

void Subject::notify() {
    for(auto o: observers)
        o->update();
}

void Subject::addObserver(Observer *o) {
    observers.push_back(o);
}
