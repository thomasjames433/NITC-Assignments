#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct item{
    int ID;
    int p;
};

typedef struct item job;

void swap(job* x, job*y)
{
    job hold = *x;
    *x = *y;
    *y = hold;
}

void heapify(job A[], int i, int n)
{
    int l = 2*i;
    
    int r = 2*i + 1;
    int largest;

    if(l<=n && A[l].p>A[i].p)
        largest = l;
    else   
        largest = i;
    if(r<=n && A[r].p>A[i].p)
        largest = r;
    if(largest!=i)
    {
        swap(&A[i],&A[largest]);
        heapify(A,largest,n);
    }
}

void BuildHeap(job A[], int n)
{
    for(int i=n/2; i>=1; i--)
    {
        heapify(A,i,n);
    }
}

void Heapsort(job A[], int n)
{
    BuildHeap(A,n);
    int h=n;
    for (int i= n; i >1; i--)
    {
        swap(&A[1],&A[i]);
        h=h-1;
        heapify(A,1,h);
    }
    
}

void next_job(job A[], int n)
{
    if(n>0)
        printf("%d\n",A[1].ID);
    else
        printf("-1\n");
}

void schedule(job A[], int n)
{
    if(n<1)
        printf("Heap underflow");
    printf("%d\n",A[1].ID);
    A[1] = A[n];
    n--;
    heapify(A,1,n);
}

void replace_priority(job A[], int id, int np, int n)
{
    int pos;
    for(int i=1; i<=n; i++)
    {
        if(A[i].ID==id)
            pos = i;
    }
    A[pos].p = np;
    while (pos>1 && A[pos/2].p<A[pos].p)
    {
        swap(&A[pos/2],&A[pos]);
        pos = pos/2;
    }
    
}

void add(job A[], int id, int p, int n)
{
    A[n].ID = id;
    A[n].p = INT_MIN;

    replace_priority(A,id,p,n);

}

void display(job A[], int n)
{
    if(n>0){
    for(int i=1; i<=n; i++)
    {
        printf("%d %d\n",A[i].ID,A[i].p);
    }
    }
    else
        printf("-1\n");
}

int main(){
    
    char sym;
    job A[100];
    int id;
    int prior;
    int n=0;
    do{

        scanf("%c",&sym);

        if(sym=='a')
        {
            scanf("%d",&id);
            
            scanf("%d",&prior);         
            n=n+1;
            add(A,id,prior,n);
        }

        if(sym=='s')
        {
            schedule(A,n);
            n--;
        }
        
        if(sym=='n')
        {
            next_job(A,n);
        }
        if(sym=='r')
        {
            scanf("%d%d",&id,&prior);
            replace_priority(A,id,prior,n);
        }
        if(sym=='d')
        {
            display(A,n);
        }

    }while(sym!='e');


    return 0;
}