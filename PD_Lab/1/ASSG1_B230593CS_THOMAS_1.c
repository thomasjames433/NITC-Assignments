#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
    scanf("%d",&A[i]);
    for(int i=1;i<n;i++){
        int temp = A[i];
        int j=i-1;
        while(j>=0 && A[j]>temp){
            A[j+1]=A[j];
            j--;
        };
        A[j+1]= temp;
    }
    for(int i=0;i<n;i++)
    printf("%d ",A[i]);
}