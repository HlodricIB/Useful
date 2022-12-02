#include <vector>
#include <iostream>
#include "to_square.h"

int main()
{
    std::vector<int> non_squared = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    To_square t_s(non_squared);
    t_s.display();
    t_s.push_more(100);
    t_s[0] = 25;
    const To_square t_s_const(non_squared);
    //t_s_const[0] = 5;
    t_s.display();
    return 0;
}
