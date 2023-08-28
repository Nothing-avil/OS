#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    printf("Orphan Process: \n");
    int x = fork();
    if(x > 0)
    {
        printf("\nParent Process, PID = %d, Parent ID = %d\n", getpid(), getppid());
        exit(0);
    }
    else
    {
        sleep(2);
        printf("\nChild Process, PID = %d, Parent ID = %d\n", getpid(), getppid());
    }
    return 0;
}
