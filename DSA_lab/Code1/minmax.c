#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int*b){
    int x=*a;
    *a=*b;
    *b=x;
}

int findlevel(int x){
    x+=1;
    int i=0;
    while(x!=0){
        x=x/2;i++;
    }
    return i;
    if(i%2==0)
        return 1;
    return 0;
}

void pushdown(int *arr,int x,int len){
    int gc=2*(2*x+1)+1;
    while(gc<len){
        int ll=gc;
        int lr=gc+1;
        int rl=gc+2;
        int rr=gc+3;
        int min=x;
        if(min>arr[ll])
            min=ll;
        if(min>arr[lr])
            min=lr;
        if(min>arr[rl])
            min=rl;
        if(min>arr[rr])
            min=rr;
        if(min==x)
            return;
        swap(&arr[min],&arr[x]);
        gc=2*(2*x+1)+1;
    }
    return;
}

void insert(int *arr,int i){
    if(i==0)
        return;
    int lev=findlevel(i);
    int p=(i-1)/2;
    
    if(lev%2==0){
        if(arr[i]<arr[p]){
            swap(&arr[i],&arr[p]);
            insert(arr,p);
            return;    
        }
        if(p==0)
            return;
        int gp=(p-1)/2;
        if(arr[i]>arr[gp]){
            swap(&arr[i],&arr[gp]);
            insert(arr,gp);        
        }
        return;
        
    }
    else{
        if(arr[i]>arr[p]){
            swap(&arr[i],&arr[p]);
            insert(arr,p);
            return;    
        }
        
        if(p==0)
            return;
        int gp=(p-1)/2;
        if(arr[i]<arr[gp]){
            swap(&arr[i],&arr[gp]);
            insert(arr,gp);        
        }
        return;
        
    }
}

int main(){
    int *arr=(int *)malloc(1000*sizeof(int));
    int i=0;
    int num=0;
    while(num!=-1){
        scanf("%d",&num);
        arr[i]=num;
        insert(arr,i);
        i++;
        for(int j=0;j<i;j++)
            printf("%d ",arr[j]);
        printf("\n");
    }
}