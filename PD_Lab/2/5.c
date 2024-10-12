#include<stdio.h>
#include<stdlib.h>

struct CLL{
    int data;
    struct CLL* next;
};
typedef struct CLL node;

node* Createnode(int val){
    node* tmp = (node*)malloc(sizeof(node));
    tmp->data = val;
    tmp->next=NULL;
}

void Insert(node* head, int val){
    node* ptr = head;
    node* p = Createnode(val);
    while(ptr->next != head){
        ptr=ptr->next;
    }
    ptr->next = p;
    p->next = head;
}

void Print(node* head){
    node* xptr = head;
    do{
        printf("%d ", xptr->data);
        xptr = xptr->next;
    }while(xptr != head);
    printf("\n");
}

int NGE(node* head, int num){
    node* x = head;
    while(x->data != num){
        x = x->next;
    }
    node* y = x->next;
    while(y != x){
        if(y->data > num){
            return (y->data);
        }
        y = y->next;
    }
    return -1;
}

int main(){
    node* head = Createnode(0);
    char c; int val, a=0, num;
    while(c != 'e'){
        scanf("%c", &c);
        if(c=='i'){
            scanf("%d", &val);
            if(a==0){
                node* z = Createnode(val);
                head->next = z;
                free(head);
                head = z;
                head->next = head;
                a++;
            }
            else{
                Insert(head, val);
            }
        }
        if(c=='p'){
            Print(head);
        }
        if(c=='g'){
            scanf("%d", &num);
            printf("%d\n", NGE(head, num));
        }
    }
    return 0;
}
