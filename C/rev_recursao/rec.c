#include <stdio.h>

int somatorio(int vet[], int n){

    if (n==1){
        return (vet[n-1]);
    }else{

        return (vet[n-1] + somatorio(vet, n-1));
    }


}

int naturais(int tam){
    
    if(tam <= 0){
        return 0;
    }

    
    naturais(tam - 1);
    printf("%d ", tam);
}

int fibonatti(int n){

    if( n == 0){

        return 0;
    }else if( n == 1){

        return 1;
    }else{
        return fibonatti(n - 1) + fibonatti(n - 2);
    }


}

int Ackermann(int m, int n){

    if( m == 0){

        return (n+1);
    }else if(n==0 && m>0){

        return Ackermann(m-1, 1);
    }else if(n > 0 && m > 0){

        return Ackermann(m-1, Ackermann(m, n-1));
    }
}

int inverso(int n, int j){

    if(n==0){

        return j;
    }

    j = (j * 10) + n%10;
    return inverso(n/10, j);
}

int binario(int n){

    if(n == 0){

        return 0;
    }else{

        binario(n/2);
        printf("%d", n%2);
    }
    
}

int main(){

    // int n, r;
    // int vet[5] = {1,2,3,4,5};

    // r = somatorio(vet, 5);
    // printf("%d", r);

    // int tam = 37;

    // naturais(tam);

    // int n = 8;

    // for(int i = 0; i < n; i++){
    //     printf("%d ", fibonatti(i));
    // }

    // printf("%d", Ackermann(3, 0));

    // printf("%d", inverso(234, 0));

    binario(5);
    

    return 0;
}