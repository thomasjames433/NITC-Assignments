#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct SLL{
    char url[100];
    struct SLL *next;
};
typedef struct SLL node;



node* Createnode(char *s){
    node* tmp = (node*)malloc(sizeof(node));
    strcpy(tmp->url, s);
    tmp->next = NULL;
}

void visit_new_page(node** top, char *s){
    
    
        node* ptr = Createnode(s);
        ptr->next = *top;
        *top = ptr;
    }


void go_back(node** top){
    if(*top==NULL){
        printf("Stack Underflow\n");
    }
    else{
        node* y = *top;
        *top=(*top)->next;
        free(y);
        printf("Navigating back to page '%s'\n", (*top)->url);
    }
}

void Clear(node** top){
    if(*top == NULL){
        printf("no history\n");
    }
    else{
    node* cursor, *next;
    cursor = *top;
    next = cursor;
    while(next->next != NULL){
        next = cursor->next;
        free(cursor);
        cursor = next;
    }
}
printf("history cleared\n");
}

void Display(node* top){
    
    node* ptr = top;
    printf("Browing History: ");
    while(ptr != NULL){
        printf("%s ", ptr->url);
        ptr = ptr->next;
    }
    printf("\n");
}


int main(){
    int n;
    node* top = NULL;
    do{
        printf("Menu:\n1. Visit New Page\n2. Go Back\n3. Clear History\n4. Display History\n5. Exit\nEnter your choice: ");
        scanf("%d", &n);
        if(n==1){
            printf("Enter URL: ");
            char string[50];
            scanf("%s", string);
            visit_new_page(&top, string);
            printf("Page: '%s' visited successfully\n", string);
        }
        if(n==2){
            go_back(&top);
            
        }
        if(n==3){
            Clear(&top);
            top = NULL;
        }
        if(n==4){
            Display(top);
        }
    }while(n != 5);
    return 0;
}