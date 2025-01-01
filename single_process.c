#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
int count=0;

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        //sleep(2);
        printf("Child Process: PID = %d Parent Process: PID = %d\n", getpid(),getppid()); 
        printf("child executed\n");} 
    else if (pid > 0) {
        printf("Parent Process: PID = %d parents parent Process: PID = %d\n", getpid(),getppid());      
        printf("parent executed\n");} 
    else {
        perror("fork failed");}
    count++;
    printf("count is: %d\n",count); //the global variable doesnt reflect the change done in child process
    printf("child pid is: %d\n",wait(NULL)); //wait joins and returns the childs pid when parent is running
    printf("who did this, %d\n",getpid());
    return 0;
}
