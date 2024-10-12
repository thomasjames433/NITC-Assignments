#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* l;
    struct node* r;
};

struct node* createNode (int a) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Failed\n");
        exit(1);
    } else {
        temp->data = a;
        temp->l = temp->r = NULL;

        return temp;
    }
}


void insertKey (struct node** root, int a) {
    if (*root == NULL) {
        *root = createNode(a);
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
    } else if (root->data == a) {
        printf("PRESENT\n");
        return;
    } else if (root->data < a) {
        return searchKey(root->r, a);
    } else if (root->data > a) {
        return searchKey(root->l, a);
    }

    printf("NOT PRESENT\n");
}

struct node* deleteKey (struct node* root, int a) {
    if (root == NULL) {
        printf("NOT PRESENT in the BST\n");
        return root;
    }

    if (a < root->data) {
        root->l = deleteKey(root->l, a);
    } else if (a > root->data) {
        root->r = deleteKey(root->r, a);
    } else {
        if (root->l == NULL) {
            struct node* temp = root->r;
            free(root);
            return temp;
        } else if (root->r == NULL) {
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

void kthSmallestUtil(struct node* Root, int k, int* count, int* result) {
    if (Root == NULL || *count >= k) {
        return;
    }
    
    kthSmallestUtil(Root->l, k, count, result);
    (*count)++;
    
    if (*count == k) {
        *result = Root->data;
        return;
    }
    
    kthSmallestUtil(Root->r, k, count, result);
}


int kthSmallest(struct node* Root, int k) {
    int count = 0;
    int result = -1;
    
    kthSmallestUtil(Root, k, &count, &result);
    printf("%d\n", result);

    return result;
}


struct node* maximum (struct node* root) {
    struct node* temp = root->r;
    while (temp->r != NULL) {
        temp = temp->r;
    }

    return temp;
}


struct node* findMin(struct node* node) {
    if (node == NULL)
        return NULL;
    while (node->l != NULL)
        node = node->l;
    return node;
}

struct node* successor(struct node* root, int data) {
    struct node* target = NULL;
    struct node* current = root;
    while (current != NULL && current->data != data) {
        if (data < current->data)
            current = current->l;
        else
            current = current->r;
    }
    target = current;

    if (target != NULL && target->r != NULL)
        return findMin(target->r);

    struct node* succ = NULL;
    current = root;
    while (current != NULL) {
        if (data < current->data) {
            succ = current;
            current = current->l;
        } else if (data > current->data) {
            current = current->r;
        } else {
            break;
        }
    }
    return succ;
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

            case 's':
                scanf("%d", &data);
                searchKey(root, data);
                break;

            case 'd':
                scanf("%d", &data);
                deleteKey(root, data);
                break;

            case 'k':
                scanf("%d", &data);
                int count = 0;
                kthSmallest(root, data);
                break;

            case 'm':
                printf("%d\n", maximum(root)->data);
                break;

            case 'n':
                scanf("%d", &data);
                printf("%d\n", successor(root, data)->data);
                break;

            case 'e':
                break;

            default:
                break;
        }
    }

}