#include <stdio.h>
#include <stdlib.h>

void resolve(int N, long long *resultado, int *vetor_de_mods){
    int i = 0;
    int somatorio = 0;
    int n;

    while (i < N){

        scanf("%d", &n);

        somatorio += n;

        somatorio%=8;

        resultado[0] += vetor_de_mods[somatorio];

        vetor_de_mods[somatorio] ++;
        i++;
  }
}
int main(){

    int N;

    int *vetor_de_mods;
    vetor_de_mods = (int*) calloc(8,sizeof(int));
    vetor_de_mods[0] = 1;

    long long resultado = 0;

    scanf("%d", &N);

    resolve(N, &resultado, vetor_de_mods);

    printf("%lld\n", resultado);
}
