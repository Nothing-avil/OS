#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int find(int n, int arr[], int a){
      int val;
      switch(a){
            case 1:
                  val=arr[0];
                 for(int i=0; i<n; i++){
                        if(val<arr[i]){
                              val=arr[i];
                        }
                  }
                  break;
            case 2:
                  val=arr[0];
                  for(int i=0; i<n; i++){
                        if(val>arr[i]){
                              val=arr[i];
                        }
                  }
                  break;
             default: 
                  printf("ERROR ");
       }
       return val;
}
void SCAN(int n, int arr[], int p, int mi, int ma, int a){
      int seek=0;
      switch(a){
            case 2:
                  seek=seek+abs(p-ma);
                  p=ma;
                  seek= seek+ abs(p-find(n, arr, a));
                  break;
            case 1:
                  seek=seek+abs(p-mi); 
                  p=mi;
                  seek= seek+ abs(p-find(n, arr, a));
                  break;
             default: 
                  printf("ERROR ");
       }
       printf("Total seek time : ");
       printf("%d\n", seek);
}
int main(){
      int n, p, mi, ma, a;
      printf("Enter disk queue size: ");
      scanf("%d", &n);
      int arr[n];
      printf("Enter queue request elements: ");
      for(int i=0; i<n; i++){
            scanf("%d", &arr[i]);
      }
      printf("Enter the head position: ");
      scanf("%d", &p);
      printf("Enter the min and max limit: ");
      scanf("%d", &mi);
      scanf("%d", &ma);
      printf("Enter the 1: for minimum  2 for maximum: ");
      scanf("%d", &a);
      SCAN(n, arr, p, mi, ma, a);
      return 0;
}
