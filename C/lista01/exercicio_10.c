#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, *pt1, *pt2;

    pt1 = &i;
    pt2 = &j;

    printf("Informe i: ");
    scanf("%d", &i);
    printf("Informe j: ");
    scanf("%d", &j);

    if( pt1 > pt2 )
    {
        printf("%d", *pt1);
    }else
    {
        printf("%d", *pt2);
    }

    return 0;
}
