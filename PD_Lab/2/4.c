#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
struct node *prev;
};

 struct node* CreateNode(int num)
{
 struct node* newnode=(struct node*)malloc(sizeof( struct node));
 if(newnode==NULL)
 {
   printf("NULL");
   return NULL;
 }
 newnode->prev=NULL;
 newnode->data=num;
 newnode->next=NULL;
 return newnode;
}  

 void ListInsert(struct node** head,struct node* x)
    {
	if(*head==NULL){
		*head=x;
		return;
	}
	struct node* temp=*head;
	while(temp->next!=NULL)temp=temp->next;
	temp->next=x;
	x->prev=temp;
}
void InitialList(struct node *head)
{
    
	struct node* temp=head;
	if(temp==NULL)
	{ 
	    printf("NULL");
     	return;
	}
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void ReverseList(struct node **head)
{
	struct node *temp=*head,*nextnode;
	struct node *prevnode=temp->prev;
	while(temp!=NULL)
	{
		nextnode=temp->next;
		temp->next=temp->prev;
		temp->prev=nextnode;
		prevnode=temp;
		temp=nextnode;
	}
	*head=prevnode;
}

int main()
{
    char input;
    struct node* head=NULL;
    int a = 0;
    int buf = 0;
    do
    {
       scanf("%c",&input);
       if (input == 'r' && a == 0) {
           buf = 1;
       }
       if (buf == 0) {
       if(input=='i')
       {
        int num;
        scanf("%d",&num);
        struct node* newnode=CreateNode(num);
        ListInsert(&head,newnode);
       }
     else if(input=='r')
       {
        ReverseList(&head);
       }
     else if(input=='p')
       {
        InitialList(head);
       }}
       a ++;
    }
    while(input!='e');
    if (buf == 1) {
        printf("NULL");
    }
}




