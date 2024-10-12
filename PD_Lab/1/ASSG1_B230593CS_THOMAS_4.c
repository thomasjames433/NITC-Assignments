#include <stdio.h>
int main(){
  int n, k;
  printf("Enter n ");
  scanf("%d",&n);
  int A[n];
  for(int i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  printf("Enter k ");
  scanf("%d",&k);

  for(int i=0;i<n;i++){
    int min=A[i];
    int c;
    int x=0;
    for(int j=i+1;j<n;j++){
      if(A[j]<min){
        min =A[j];
        x++;
        c=j;
      }
    }
    if(x!=0){
      A[c]=A[i];
    A[i]=min;
    }
}
  printf("%d",A[k-1]);

}