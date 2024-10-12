#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    int n;
    int length;
    int position = 0;
    char sample[50];
    char **strings;
    scanf("%d", &n);

    strings = malloc(sizeof(char *) * n);

    while (getchar() != '\n');

    for (int i = 0; i < n; i ++) {
        fgets(sample, 50, stdin);
        length = strlen(sample);
        sample[length - 1] = '\0';
        strings[i] = malloc(sizeof(char) * length);
        strcpy(strings[i], sample);
        if (strlen(strings[i]) > strlen(strings[position])) {
            position = i;
        }
    }

    printf("%s", strings[position]);

    for (int i = 0; i < n; i ++) {
        free(strings[i]);
    }

    free(strings);

    return 0;
}
