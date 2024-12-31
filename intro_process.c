#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        //sleep(2);
        printf("Child Process: PID = %d\n", getpid());
    } else if (pid > 0) {
        printf("Parent Process: PID = %d\n", getpid());
        wait(NULL);
        //sleep(2);
    } else {
        perror("fork failed");
    }
    return 0;
}
