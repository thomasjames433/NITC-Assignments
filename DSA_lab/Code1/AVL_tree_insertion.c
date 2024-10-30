#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* left;
    struct node* right;
};

struct node* createnode(int val){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->val=val;
    new->left=NULL;
    new->right=NULL;
    return new;
}

int max(int a,int b){
    if(a>b)
        return a;
    return b;
}

int height(struct node* root){
    if(root==NULL)
        return 0;
    else
        return 1+max(height(root->left),height(root->right));
}

int balancefactor(struct node* root){
    if(root==NULL)
        return 0;
    return height(root->left)-height(root->right);

}



struct node *rightrotate(struct node *x){
    struct node *y=x->left;
    struct node *a=y->right;
    y->right=x;
    x->left=a;
    
    return y;

}

struct node *leftrotate(struct node *x){
    struct node *y=x->right;
    struct node *a=y->left;
    y->left=x;
    x->right=a;

    return y;
}

struct node * insertnode(struct node *root,int val){
    if(root==NULL){
        return createnode(val);
        }
    else if(val<root->val)
        root->left=insertnode(root->left,val);
    else
        root->right=insertnode(root->right,val);  
    
    int bf=balancefactor(root);
    if(bf==2){
        if(root->left->left)
            root=rightrotate(root);
        else{
            root->left=leftrotate(root->left);
            root=rightrotate(root);
        }
    }
    if(bf==-2){
        if(root->right->right)
            root=leftrotate(root);
        else{
            root->right=rightrotate(root->right);
            root=leftrotate(root);
        }
    }
    return root;
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

void Levelorder(struct node *root){
    struct node **q1=(struct node **)malloc(1000*sizeof(struct node*));
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
    int a;
    scanf("%d",&a);
    struct node *root=NULL;
    while(a!=-1){
        root=insertnode(root,a);
        scanf("%d",&a);
    }
    Levelorder(root);

}