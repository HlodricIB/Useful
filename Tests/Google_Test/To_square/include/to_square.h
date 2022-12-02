#ifndef TO_SQUARE_H
#define TO_SQUARE_H

#include <vector>
#include <iostream>

class To_square
{
private:
    std::vector<int> sqrs;
public:
    To_square() = default;
    To_square(const std::vector<int>&);
    ~To_square() { }
    void push_more(int i);
    int& operator[](int);
    int operator[](int) const;
    size_t size() const;
    void display() const;
};

#endif // TO_SQUARE_H
