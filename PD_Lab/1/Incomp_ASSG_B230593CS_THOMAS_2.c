#include <stdio.h>
#include <string.h>
int main(){
    int n;
    printf("Enter no. ");
    scanf("%d",&n);
    char A[n][100];
    for(int i=0;i<n;i++){
    printf("Enter book no %d \n",i);
    scanf("%s",A[i]);
    }

      
    for(int i=1;i<n;i++){
        char temp[100];
        for(int p=0;p<100;p++)
        temp[p]=A[i][p];
        int j=i-1;
        int a=temp[0];
        int b= A[j][0];
        while(j>=0 && b>a){
            
            for(int x=0;x<100;x++){
                A[j+1][x]=A[j][x];
            }
         b= A[j-1][0];
            j--;
        };
        for(int x=0;x<100;x++){
            A[j+1][x]=temp[x];
        }
for(int i=0;i<n;i++)
    printf("%s ",A[i]);
    printf("\n");
    }
for(int i=0;i<n;i++)
    printf("%s ",A[i]);

}
