#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    printf("Zombie Process: \n");
    int x = fork();
    if(x > 0)
    {
        sleep(2);
        printf("\nParent Process, PID = %d, Parent ID = %d\n", getpid(), getppid());
    }
    else
    {
        printf("\nChild Process, PID = %d, Parent Id = %d\n", getpid(), getppid());
        exit(0);
    }
    return 0;
}
