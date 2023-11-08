#include <stdio.h>

#define TAM_VET 14

int maior_elemento(int *v, int tam, int pos){
    if (pos == tam-1)
        return v[pos];

    int a = v[pos];
    int b = maior_elemento(v, tam, pos+1);
    if (a > b){
        return a;
    }else{
        return b;
    }
}

int main(){
    int v[TAM_VET];
    int i;

    for (i=0; i<TAM_VET; i++){
        v[i] = i * 2;
    }

    printf("\nMaior eh %d\n\n", maior_elemento(v, TAM_VET, 0));
    return 0;
}
