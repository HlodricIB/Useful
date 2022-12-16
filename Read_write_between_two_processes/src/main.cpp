#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>
#include <cstdio>
#include <cerrno>
#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    /*FILE* cmd;
    int status;

    cmd = popen("gnome-terminal", "w");
    fprintf(cmd, "echo \"1\"");
    //std::cout << ret << std::endl;
    status = pclose(cmd);
    if (WIFEXITED(status)) {
        if (WEXITSTATUS(status) == EXIT_SUCCESS)
            fprintf(stderr, "No errors.\n");
        else
            fprintf(stderr, "Command failed with exit status %d.\n", WEXITSTATUS(status));
    } else
        if (WIFSIGNALED(status))
            fprintf(stderr, "Command killed by signal %d.\n", WTERMSIG(status));
        else
            fprintf(stderr, "Command failed.\n");*/
    pid_t pid;
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
    }
    if (!pid)
    {
        auto ret = execlp("gnome-terminal", "gnome-terminal", "sh /home/nikita/C++/Useful/Read_write_between_two_processes/commands.sh", (char*)NULL);
        if (ret == -1)
        {
            perror("execlp");
            return EXIT_FAILURE;
        }
    }
    if (pid > 0)
    {
        int status;
        wait(&status);
    }
    /*auto fd = open("/dev/tty", O_WRONLY);
    if (fd == -1)
    {
        perror("open");
        return EXIT_FAILURE;
    }
    close(fd);*/
    return 0;
}
