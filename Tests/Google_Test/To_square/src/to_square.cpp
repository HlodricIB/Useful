#include "to_square.h"

To_square::To_square(const std::vector<int>& non_squared): sqrs(non_squared.size())
{
    size_t i = 0;
    for (auto iter = non_squared.begin(); iter != non_squared.end(); ++iter)
    {
        sqrs[i++] = (*iter) * (*iter);
    }
}

void To_square::push_more(int i)
{
    sqrs.push_back(i * i);
}

int& To_square::operator[](int i)
{
    return sqrs[i];
}

int To_square::operator[](int i) const
{
    return sqrs[i];
}

size_t To_square::size() const
{
    return sqrs.size();
}

void To_square::display() const
{
    for (auto& i : sqrs)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}
