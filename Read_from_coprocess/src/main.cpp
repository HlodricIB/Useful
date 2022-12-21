#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdio>
#include <cerrno>
#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    std::string path;
    std::ifstream coprocess_path("../../path_to_coprocess_bin.txt", std::ios::in);
    if (!coprocess_path.is_open())
    {
        std::cerr << "Path to coprocess executable not founded" << std::endl;
        return EXIT_FAILURE;
    }
    std::getline(coprocess_path, path);
    coprocess_path.close();

    FILE* coprocess_in = popen(path.c_str(), "r");
    if (coprocess_in == nullptr)
    {
        std::perror("Unable to open pipe to coprocess");
    }

    while (std::fgetc(coprocess_in) != 127);
    auto i = std::fgetc(coprocess_in);
    if (i != static_cast<int>('1'))
    {
        std::cerr << "Something went wrong" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "Ok!" << std::endl;
    if (pclose(coprocess_in))
    {
        std::perror("pclose failed");
    }
    return 0;
}
