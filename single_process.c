#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
    int n;
    pid_t pid = fork();
    
    if(pid==0)
    n=1;
    else
    n=6;

    for(int i=n;i<n+5;i++)
    printf(" %d ",i),fflush(stdout);

    if(pid>0)
    wait(NULL);
    
    printf("\n");
    return 0;
}
