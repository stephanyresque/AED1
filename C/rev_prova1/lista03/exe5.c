#include <stdio.h>

int inverso(int n, int j){

    if(n==0){

        return j;
    }

    j = (j * 10) + n%10;
    return inverso(n/10, j);
}

int main(){

    printf("%d", inverso(138000 , 0));

    return 0;
}