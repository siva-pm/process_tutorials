#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
int main() {
    pid_t pid1 = fork();
    pid_t pid2 = fork();

    if(pid1==0)
    {
        if(pid2==0)
        printf("child of B %d, this is C %d\n",getppid(),getpid());
        else
        printf("child of A %d, this is B %d\n",getppid(),getpid());
    }
    else
    {
        if(pid2==0)
        printf("child of A %d, this is D %d\n",getppid(),getpid());
        else
        printf("this is A %d\n",getpid());
    }

    while(wait(NULL)!=-1 || errno != ECHILD);

    return 0;
}
