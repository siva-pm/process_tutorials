#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void task_doer(int task_num)
{
    printf("task %d (PID: %d) started, Parent PID: %d\n", task_num, getpid(),getppid());
    sleep(2+ task_num); // real work should be inserted here
    printf("task %d (PID: %d) completed\n\n2",task_num,getpid());
}

int main() {
    int count;
    printf("enter the no. of child process to create: ");
    scanf("%d",&count);
    pid_t cpids[count];

    for(int i=0;i<count;i++)
    {
        pid_t pid=fork();
        if (pid == 0) 
        printf("Child Process: PID = %d\n", getpid()); 
        else if (pid > 0) 
        cpids[i]=pid;
        else {
        perror("fork failed");
        exit(1);}
    }
    
    for(int i=0; i<count;i++)
    {
        int status;
        pid_t pid=wait(&status);
        if(WIFEXITED(status))
        printf("pid: %d exited with status %d\n ",pid,WEXITSTATUS(status));
    }

    printf("all child processes completed. parent exiting. \n");
    return 0;
}
