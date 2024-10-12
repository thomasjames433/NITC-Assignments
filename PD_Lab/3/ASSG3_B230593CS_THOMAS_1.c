#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct item{
    char name[50];
    int mileage;
};

typedef struct item car;

void swap(car* x, car*y){
    car hold = *x;
    *x=*y;
    *y=hold;
}

void Heapify(car A[], int i, int n)
{
    int l = 2*i;
    int r = 2*i + 1;
    int largest = i;

    if (l<=n && A[l].mileage>A[i].mileage)
    {
        largest = l;
    }

    if (r<=n && A[r].mileage>A[i].mileage)
    {
        largest = r;
    }

    if(largest!=i)
    {
        swap(&A[i],&A[largest]);
        Heapify(A,largest,n);
    }
}

void BuildHeap(car A[], int n)
{
    for(int i=n/2; i>=1; i--)
    {
        Heapify(A,i,n);
    }
}

void HeapSort(car A[], int n)
{
    BuildHeap(A,n);
    int h =n;

    for(int i=n; i>=2; i--)
    {
        swap(&A[1],&A[i]);
        h = h-1;
        Heapify(A,1,h);
    }
}

int main(){

    int n;
    scanf("%d",&n);
    int e,sum;

    if(n>0 && n<=1000){

        car *A = (car*)malloc((n+1)*sizeof(car));
        getchar();
        char per[50];
        for(int i=1; i<=n;i++)
        {
            fgets(per,50,stdin);
            int j=0;
            sum=0;
            per[strlen(per)-1]='\0';
            while(per[strlen(per)-1]!=':')
            {
                e = pow(10,j);
                sum=sum+(per[strlen(per)-1] -48)*e;
                per[strlen(per)-1]='\0';
                j++;
            }
   

            strcpy(A[i].name,per);
            A[i].mileage = sum;
            
        }

        HeapSort(A,n);
        for(int i=n; i>=1; i--)
        {
            printf("%s %d\n",A[i].name,A[i].mileage);
        }
    }
    else
        printf("Invalid input");

    return 0;
}