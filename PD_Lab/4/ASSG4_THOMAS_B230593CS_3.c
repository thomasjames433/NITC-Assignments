#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* l;
    struct node* r;
    int key;
};

typedef struct node* node;
node buildTree(char *string, int *position) {
    if (string[*position] == '('){
        (*position)+=2;
        if (string[*position]==')') {
            (*position)+=2;
            return NULL;
        }
        int n = 0;
        while (string[*position]>='0' && string[*position]<='9') {
            n=n*10+(string[*position]-'0');
            (*position)++;
        }
        if(string[*position]==' ')
        (*position)++;
        node newnode=(node)malloc(sizeof(struct node));
        newnode->key=n;
        newnode->l=buildTree(string, position);
        newnode->r=buildTree(string, position);
        (*position)+=2;
        return newnode;
    }
    return NULL;
}

node Search(node root,int x)
{
    if(root==NULL || root->key==x)
    return root;
    node l=Search(root->l,x);
    node r=Search(root->r,x);
    if(l!=NULL)
    return l;
    else
    return r;
}

void Print(node root,int k,int depth)
{
    if(root==NULL)
    return;
    if(depth==k)
    printf("%d ",root->key);
    Print(root->l,k,depth+1);
    Print(root->r,k,depth+1);
}

int main()
{
    char expr[500];
    fgets(expr,500,stdin);
    int x,k;
    scanf("%d %d",&x,&k);
    int position=0;
    node root=buildTree(expr,&position);
    node X=Search(root,x);
    Print(X,k,0);
}