#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    char name[100];
    int marks;
};
void Sort(struct student *students, int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (students[j].marks < students[min].marks)
            {
                min = j;
            }
        }
        if (min != i)
        {
            struct student temp = students[min];
            students[min] = students[i];
            students[i] = temp;
        }
    }
}

int main()
{
    int n, r;
    scanf("%d", &n);
    struct student *students = (struct student *)malloc(n * sizeof(struct student));
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", students[i].name, &students[i].marks);
        if (students[i].marks < 0 || students[i].marks > 100)
        {
            printf("Error - Total mark out of the range\n");
            return 1;
        }
    }
    scanf("%d", &r);
    int y = n - r;
    Sort(students, n);
    printf("%s %d", students[y].name, students[y].marks);
    free(students);
    return 0;
}
 