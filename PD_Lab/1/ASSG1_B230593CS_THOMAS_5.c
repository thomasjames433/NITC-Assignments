#include <stdio.h>
int main(){
  int n;
  printf("Enter no ");
  scanf("%d",&n);
  int A[n];
  for(int i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
    int k=0;
  for(int i=0;i<n-1;i++){

    int c=0;
    for(int j=0;j<n-1-i;j++){
      int a=A[j];
      int b= A[j+1];
      if(A[j]>A[j+1]){
        A[j]=b;
        A[j+1]=a;
        k++;
        c=1;
      }
    }
    if(c==0)
    break;
  }
  for(int i=0;i<n;i++){
    printf("%d ",A[i]);
}
printf("\n");
printf("%d",k);
}