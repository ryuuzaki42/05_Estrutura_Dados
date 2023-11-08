#include<stdio.h>

long fibonacci_iterativo(int num){
    if (num == 0 || num == 1){
        return num;
    }

    long i = 0;
    long j = 1;
    long k, t;
    for(k = 1; k < num; k++){
        t = i + j;
        i = j;
        j = t;
    }

    return j;
}

long fibonacci_recursivo(int num){
    if (num == 0 || num == 1)
        return num;

    return fibonacci_recursivo(num - 1) + fibonacci_recursivo(num - 2);
}

#define MAX_MEMO 100
long memo[MAX_MEMO]; // Inicializar todos com -1

long fibonacci_memoizacao (int num) { // memoização / memoization
    if (num == 0 || num == 1)
        return num;

    if ( memo[num] != -1)
        return memo[num];

    memo[num] = fibonacci_memoizacao(num - 1) + fibonacci_memoizacao(num - 2);
    return memo[num];
}

int main(){
    int x, i;

    printf("Digite a posição desejada da sequência de Fibonacci: ");
    scanf("%d", &x);

    printf("\nfibonacci_iterativo : %ld", fibonacci_iterativo(x));
    printf("\nfibonacci_recursivo : %ld", fibonacci_recursivo(x));

    for (i = 0; i < MAX_MEMO; i++) {
        memo[i] = -1;
    }
    printf("\nfibonacci_memoizacao: %ld\n\n", fibonacci_memoizacao(x));

    return 0;
}
