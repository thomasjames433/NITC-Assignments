#include <stdio.h>
#include <stdlib.h>

struct nd
{
    int data;
    struct nd *next;
};
typedef struct nd node;

node *CreateNode(int val)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

void InsertNode(node *head, int val)
{
    node *x = head;
    while (x->next != NULL)
    {
        x = x->next;
    }
    x->next = CreateNode(val);
}

void Sort(node *head)
{
    node *x = head;
    int b, c;
    while (x != NULL)
    {
        c = x->data;
        b = x->data;
        node *y = x;
        node *z = x;
        while (y != NULL)
        {
            if (y->data < c)
            {
                c = y->data;
            }
            y = y->next;
        }
        while (z->data != c)
        {
            z = z->next;
        }
        x->data = c;
        z->data = b;
        x = x->next;
    }
}

void Print(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    char a;
    int val, b = 0;
    node *head = CreateNode(0);
    node *z = head;
    while (a != 'e')
    {
        scanf("%c", &a);
        if (a == 'i')
        {
            scanf("%d", &val);
            if (b == 0)
            {
                z->next = CreateNode(val);
                b++;
                z = z->next;
                free(head);
                head = z;
            }
            else
            {
                InsertNode(head, val);
            }
        }
        if (a == 's')
        {
            Sort(head);
        }
        if (a == 'p')
        {
            Print(head);
        }
    }
    return 0;
}
