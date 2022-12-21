#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <sys/wait.h>
#include<cctype>

int main()
{
    auto status = std::system("sudo -S ls");
    putchar(127);
    if (WIFEXITED(status))
    {
        if (WEXITSTATUS(status) == EXIT_SUCCESS)
        {
            std::putchar(static_cast<int>('1'));
        }
    } else {
        std::putchar(static_cast<int>('0'));
    }
    return 0;
}
