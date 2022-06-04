#pragma once

class Observer
{
public:
    virtual void update() = 0;
    virtual ~Observer() {} //must define this, as Observer is inherited and there won't be proper destruction, otherwise...
};