#include <stdio.h>

int somatorio(int vet[], int n){

    if (n==1){
        return (vet[n-1]);
    }else{

        return (vet[n-1] + somatorio(vet, n-1));
    }


}

int naturais(int tam){
    
    if(tam <= 0 ){
        return 0;

    }

    printf("%d ", tam);
    return (tam - 1);
    
    
}

int main(){

    // int n, r;
    // int vet[5] = {1,2,3,4,5};

    // r = somatorio(vet, 5);
    // printf("%d", r);

    int tam = 5;

    naturais(tam);

    return 0;
}