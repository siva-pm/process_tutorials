#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
int count=0;

int main() {
    pid_t pid1 = fork();

     if(pid1==0)
     printf("this is child PID = %d of parent PID = %d\n", getpid(),getppid()); 
     else
     printf("parent exec %d\n",getpid());
    
    pid_t pid2 = fork();
   
     if(pid2==0)
     printf("this is child PID = %d of parent PID = %d\n", getpid(),getppid()); 
     else
     printf("parent exec %d\n",getpid());

    if(pid1>0 && pid2>0)
    {
    printf("\nfinished child pid: %d\n",wait(NULL));
    printf("\nfinished child pid: %d\n",wait(NULL));
    }
    printf("\nwho did this, %d\n",getpid());
    return 0;
}
