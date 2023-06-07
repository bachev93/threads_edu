#include <iostream>

#include <unistd.h>
#include <wait.h>

int main(int, char**) {
    std::cout << "Hello, world!" << std::endl;
    
    /*
    pid_t pid = fork();

    std::cout << pid << std::endl;
    
    int status;
    if(pid == 0) {
        std::cout << "It's child process" << std::endl;
        // char* args[] = {"ls", "-l", NULL};
        // auto res = execv("ls", args);
        auto res = execlp("ls", " ", NULL);
        std::cout << "res of exec: " << res << std::endl;
        exit(0);
    } else {
        waitpid(pid, &status, 0);
        std::cout << "It's parent process" << std::endl;
        
    }
    */

    return 0;
}
