#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void FCFS(int n, int arr[], int p){
      int seek=0;
      for(int i=0; i<n; i++){
            seek=seek+abs(p-arr[i]);
            p=arr[i];
       }
       printf("Sequence for accepted request: \n");
       for(int i=0; i<n; i++){
            printf("%d\n", arr[i]);
      }
       printf("Total seek time : ");
       printf("%d\n", seek);
}
int main(){
      int n, p;
      printf("Enter disk queue size: ");
      scanf("%d", &n);
      int arr[n];
      printf("Enter queue request elements: ");
      for(int i=0; i<n; i++){
            scanf("%d", &arr[i]);
      }
      printf("Enter the head position: ");
      scanf("%d", &p);
      FCFS(n, arr, p);
      return 0;
}
