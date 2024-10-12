#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);

    char formula[n][40];

    for(int i=0; i<n; i++)
    {
        scanf("%s",formula[i]);
    }

    int check = 0;

    for(int i=0; i<n; i++)
    {
        int p = 0;
        for(int j=0; j<strlen(formula[i]); j++)
        {
            if(formula[i][j]=='(')
                p++;
            if(formula[i][j]==')')
                p--;
            if(p<0)
                break;
        }
        if(p==0)
            check++;
    }

    printf("%d\n",check);
    return 0;
}