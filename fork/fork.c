#include<stdio.h>
#include<unistd.h>
int main()
{
    fork();
    printf("PID is : %d\n", getpid());
}
