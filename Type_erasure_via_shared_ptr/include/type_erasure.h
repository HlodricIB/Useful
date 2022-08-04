#ifndef TYPE_ERASURE_H
#define TYPE_ERASURE_H

#include <string>
#include <memory>
#include <iostream>
#include <vector>

class Base
{
public:
    virtual ~Base() { }
    virtual void handle(std::shared_ptr<void>) = 0;
};

class H : public Base
{
public:
    void handle(std::shared_ptr<void> args) override {
        auto v_p =(std::reinterpret_pointer_cast<std::vector<std::string>>(args));
        std::cout << (*v_p)[0] << std::endl;
    }
};

#endif // TYPE_ERASURE_H
