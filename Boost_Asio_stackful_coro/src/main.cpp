#include "stackful_coro.h"

int main()
{
    Timer timer(2, {std::chrono::seconds(2), std::chrono::seconds(5)});
    timer.run();
    return 0;
}
