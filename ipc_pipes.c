#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd[2]; // fd[0] - read end, fd[1] - write end
    int x;
    if (pipe(fd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) {   // Child process
        close(fd[0]); // Close read end
        printf("Child should send? \n");
        scanf("%d",&x);
        write(fd[1], &x, sizeof(x)); 
        close(fd[1]); // Close write end
        } 
    else if (pid > 0) {// Parent process
        close(fd[1]); // Close write end
        read(fd[0], &x, sizeof(x));
        printf("Parent received: %d\n",x);
        close(fd[0]); // Close read end
        } 
    else {
        perror("Fork failed");
        return 2;
    }

    return 0;
}
