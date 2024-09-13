#include <stdio.h>

int main() {
    int S;
    int N2, N5, N10, N20, N50, N100;


    scanf("%d", &S);
    scanf("%d %d %d %d %d %d", &N2, &N5, &N10, &N20, &N50, &N100);


    int dp[S + 1];


    for (int i = 0; i <= S; i++) {
        dp[i] = 0;
    }

    dp[0] = 1;


    int notas[] = {2, 5, 10, 20, 50, 100};
    int quantidades[] = {N2, N5, N10, N20, N50, N100};


    for (int i = 0; i < 6; i++) {
        int valorNota = notas[i];
        int quantidadeDisponivel = quantidades[i];


        for (int j = S; j >= valorNota; j--) {
            for (int k = 1; k <= quantidadeDisponivel && k * valorNota <= j; k++) {
                dp[j] += dp[j - k * valorNota];
            }
        }
    }

    printf("%d\n", dp[S]);

    return 0;
}
