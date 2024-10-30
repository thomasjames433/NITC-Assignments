#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *left;
    struct node *right;
};

struct node *createnode(int val){
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->val=val;
    new->left=NULL;
    new->right=NULL;
    return new;
}

void maketree(struct node *root,int in[], int pre[], int *x, int first, int last, int n){
    if((*x)>n || first>last)
    return;
    int cur=first;
    while( cur<=last && in[cur]!=pre[*x])
    cur++;
    if(cur>last)
    return ;

    root->val=pre[*x];
    (*x)++;
    if(cur>first){
        root->left=createnode(-1);
        maketree(root->left,in,pre,x,first,cur-1,n);
    }
    if(cur<last){
        root->right=createnode(-1);
        maketree(root->right,in,pre,x,cur+1,last,n);
    }
}
void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->val);
        
    }
}

void enqueue(struct node **abc,int *front, int *rear, struct node *address){
    if(*front==-1 && *rear==-1){
        (*front)++;
    }

    (*rear)++;
    abc[*rear]=address;
    
}

void dequeue(int *front){
    (*front)++;
}

void Levelorder(struct node *root,int n){
    struct node **q1=(struct node **)malloc(n*sizeof(struct node*));
    int front=-1;
    int rear=-1;
    enqueue(q1,&front,&rear,root);

    while(front<=rear){
        struct node *temp=q1[front];
        printf("%d ",temp->val);

        if(temp->left!=NULL){
            enqueue(q1,&front,&rear,temp->left);
        }
        if(temp->right!=NULL){
            enqueue(q1,&front,&rear,temp->right);
        }
        dequeue(&front);
    }
}

int main(){
    printf("Enter no of nodes: ");
    int n;
    scanf("%d", &n);
    int in[n];
    int pre[n];
    for(int i=0;i<n;i++)
    scanf("%d",&in[i]);
    for(int i=0;i<n;i++)
    scanf("%d",&pre[i]);
    struct node *root=createnode(-1);
    int x=0;
    maketree(root,in,pre,&x,0,n-1,n);
    Levelorder(root,n);
    }