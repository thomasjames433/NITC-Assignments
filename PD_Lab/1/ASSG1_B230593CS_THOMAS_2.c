#include <stdio.h>
#include <string.h>

int main () {
    int n;
    scanf("%d", &n);
    getchar();
    char A[n][100];
    for (int i = 0; i < n; i ++) {
        fgets(A[i], sizeof(A[i]), stdin);
    }

    for (int i = 1; i < n; i ++) {
        char key[100];
        strcpy(key, A[i]);
        int j = i - 1;

        while (j >= 0 && A[j][0] > key[0]) {
            strcpy(A[j + 1], A[j]);
            j --;
        }

        strcpy(A[j + 1], key);
    }

    for (int i = 0; i < n; i ++) {
        printf("%s", A[i]);
    }
}