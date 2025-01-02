#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
    pid_t pid = fork();

    if(pid==0)
    sleep(2);    //put child process to sleep for awhile

    printf("current id: %d, parent id: %d \n",getpid(),getppid());
    return 0;
}
