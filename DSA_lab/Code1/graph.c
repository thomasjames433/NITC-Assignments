#include <stdio.h>
#include <stdlib.h>

struct graph{
    int f;int r;
    int size;
    int *arr;
};

void enq(struct graph *a,int x){
    a->r++;
    a->arr[a->r]=x;
}

void deq(struct graph *a){
    a->f++;
}

void dfs(int i,int a[7][7],int visited[7]){
    printf ("%d ",i);
    visited[i]=1;
    for(int j=0;j<7;j++){

        if(a[i][j] && !visited[j])
            dfs(j,a,visited);
    }
}

int main(){
    struct graph *abc=(struct graph*)malloc(sizeof(struct graph));
    abc->size=7;
    abc->f=0;
    abc->r=0;
    abc->arr=(int *)malloc(7*sizeof(int));
    int visited[7]={0,0,0,0,0,0,0};
    int a[7][7]={
        {0, 1, 0, 0, 1, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 1},
        {0, 0, 1, 0, 1, 1, 0},
        {1, 0, 0, 1, 0, 1, 0},
        {0, 0, 0, 1, 1, 0, 1},
        {0, 0, 1, 0, 0, 1, 0}
    };
    
    dfs(1,a,visited);
    //BFS
    // abc->f=0;
    // abc->r=-1;
    // int i=2;
    // printf("%d ",i);
    // visited[i]=1;
    // enq(abc,i);
    // while(abc->f<=abc->r){
    //     int x=abc->arr[abc->f];
    //     deq(abc);

    //     for(int j=0;j<7;j++){
    //         if(a[x][j] && visited[j]!=1){
    //             enq(abc,j);
    //             printf("%d ",j);
    //             visited[j]=1;
    //         }
    //     }
    // }
}