#include<stdio.h>
#include<unistd.h>
int main()
{
    int x;
    x=fork();
    if(x==0){
        printf("Child PID is : %d and parentPPID %d\n", getpid(), getppid());
    }
    else if(x==1){
        printf("Parent PID is : %d and PPID\n", getpid(), getppid());
    }
    return 0;
}
