#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* l;
    struct node* r;
};

struct node* createNode (int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Failed\n");
        exit(1);
    } else {
        temp->data = data;
        temp->l = temp->r = NULL;

        return temp;
    }
}

void insertKey (struct node** root, int a) {
    if (*root == NULL) {
        *root = createNode(a);
        return;
    } else if ((*root)->data > a) {
        insertKey(&((*root)->l), a);
    } else if ((*root)->data < a) {
        insertKey(&((*root)->r), a);
    }
}

void searchKey (struct node* root, int a) {
    if (root == NULL) {
        printf("NOT PRESENT\n");
        return;
    } else if (a == root->data) {
        printf("PRESENT\n");
        return;
    } else if (a < root->data) {
        return searchKey(root->l, a);
    } else {
        return searchKey(root->r, a);
    }

    printf("NOT PRESENT\n");
}

void inOrder (struct node* root) {
    if (root != NULL) {
        inOrder(root->l);
        printf("%d ", root->data);
        inOrder(root->r);
    }
}

void preOrder (struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->l);
        preOrder(root->r);
    }

}

void postOrder (struct node* root) {
    if (root != NULL) {
        postOrder(root->l);
        postOrder(root->r);
        printf("%d ", root->data);
    }

}


struct node* deleteKey(struct node* root, int a) {
    if (root == NULL) {
        printf("NOT PRESENT\n");
        return root;
    }
        
    if (a < root->data) {
        root->l = deleteKey(root->l, a);
    } else if (a > root->data) {
        root->r = deleteKey(root->r, a);
    }
        
    else {
        if (root->l == NULL) {
            struct node* temp = root->r;
            free(root);
            return temp;
        }
        else if (root->r == NULL) {
            struct node* temp = root->l;
            free(root);
            return temp;
        }

        struct node* temp = root->r;
        while (temp->l != NULL) {
            temp = temp->l;
        }
            
        root->data = temp->data;
        root->r = deleteKey(root->r, temp->data);
    }

    return root;
}

int main () {
    struct node* root = NULL;
    char choice;
    int data;
    while (choice != 'e') {
        choice = getchar();
        switch (choice) {
            case 'i':
                scanf("%d", &data);
                insertKey(&root, data);
                break;

            case 'p':
                 if (root == NULL){
                printf("NULL\n");
            }
            else{
                inOrder(root);
                printf("\n");}

                break;

            case 'd':
                scanf("%d", &data);
                deleteKey(root, data);
                break;
            
            case 's':
                scanf("%d", &data);
                searchKey(root, data);
                break;
            
            case 't':
               if (root == NULL){
                printf("NULL\n");
            }
            else{
                preOrder(root);
                printf("\n");}

                break;
            
            case 'b':
                if (root == NULL){
                printf("NULL\n");
            }
            else{
                postOrder(root);
                printf("\n");}

                break;

            case 'e':
                break;

            default:
                break;
        }
    }
}