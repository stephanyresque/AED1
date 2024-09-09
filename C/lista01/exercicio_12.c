#include <stdio.h>
#include <stdlib.h>

int main()
{
    int var;
    int *pt1 = &var;
    int **pt2 = &pt1;
    int ***pt3 = &pt2;

    printf("Digite var: ");
    scanf("%d", &var);

    printf("%d\n", 2*(*pt1));
    printf("%d\n", 3*(**pt2) );
    printf("%d\n", 4*(***pt3) );





    return 0;
}
