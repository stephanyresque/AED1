#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   clock_t inicio, fim;
   unsigned long int tempo;
      
   inicio = clock();
   /* coloque seu código aqui */
   fim = clock();
      
   tempo = (fim- inicio) * 1000 / CLOCKS_PER_SEC;
   printf("tempo: %lu milissegundo\n", tempo);
   return 0;
}