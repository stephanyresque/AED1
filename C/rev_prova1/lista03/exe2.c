#include <stdio.h>

int sequencia(int n){

    if(n == 0){
        return 1;
    }else{
        sequencia(n-1);
        printf("%d ", n);
    }
}

int main(){

    sequencia(37);

    return 0;
}