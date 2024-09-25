#include <stdio.h>

int fibonacci(int n){

    if(n == 0){
        return 0;
    }else if(n==1){
        return 1;
    }else{

        return fibonacci(n-2) + fibonacci(n-1);
    }
    
}

int main(){

    int r, i;

    for(i=0;i<8;i++){
        r = fibonacci(i);
        printf("%d ", r);
    }
    return 0;
}