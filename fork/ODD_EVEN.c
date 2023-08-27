#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("Enter the size of array: ");
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("enter array elements : \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int p = fork();
    if(p==0){
        int s = 0;
        for(int i = 0; i < n ;i++){
            if(arr[i]%2 == 0)
            s+=arr[i];
        }
        printf("Even sum = %d, Process ID = %d, Parent ID = %d\n", s, getpid(), getppid());
    }
    else{
        sleep(1);
        int s = 0;
        for(int i = 0; i < n ;i++) {
            if(arr[i]%2 != 0)
                s+=arr[i];
        }
        printf("\nODD sum = %d, Process ID = %d, Parent ID = %d \n", s, getpid(), getppid());
    }
    return 0;
}
