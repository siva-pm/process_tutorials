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
        wait(NULL);        
        printf("parent executed\n");} 
    else {
        perror("fork failed");}
    count++;
    printf("count: %d\n",count);
    return 0;
}
