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

// int fibonatti(int n){

//     return ()
// }

int main(){

    // int n, r;
    // int vet[5] = {1,2,3,4,5};

    // r = somatorio(vet, 5);
    // printf("%d", r);

    // int tam = 37;

    // naturais(tam);

    return 0;
}