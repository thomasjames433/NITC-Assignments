#include <stdio.h>


int partition(int A[], int lb, int ub) {
    int i = lb;
    int j = ub;
    int p = A[lb];

    while(i < j) {
        while(A[i] <= p) {
            i ++;
        }

        while(A[j] > p) {
            j --;
        }

        if(i < j) {
            int x = A[i];
            A[i] = A[j];
            A[j] = x;
        }     
    }

    int x = A[lb];
    A[lb] = A[j];
    A[j] = x;
        
    return j;
}


void quickSort(int A[], int lb, int ub) {
    if(lb < ub) {
        int x = partition(A, lb, ub);
        quickSort(A, lb, x - 1);
        quickSort(A, x + 1, ub);
    }
}


int main() {
    int n;
    scanf("%d", &n);
    
        int A[n];

        for(int i = 0; i < n; i ++) 
            scanf("%d", &A[i]);
            
            quickSort(A, 0, n - 1);
            for(int i = 0; i < n; i ++) {
                printf("%d ", A[i]);
            }
        } 
        
    
