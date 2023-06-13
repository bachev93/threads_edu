#include <iostream>

#include <unistd.h>
#include <wait.h>

int main() {
    // create new process
    pid_t pid = fork();
    std::cout << "pid is: " << pid << std::endl;

    int status;
    if (pid == 0) {
        std::cout << "It's child process" << std::endl;
        // execute program "ls -l"
        auto res = execlp("ls", " ", "-l", NULL);
        std::cout << "res of exec: " << res << std::endl;
        exit(0);
    } else {
        waitpid(pid, &status, 0);
        std::cout << "It's parent process" << std::endl;
    }

    return 0;
}
