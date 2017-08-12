#include <stdio.h>
#include <stdlib.h>
int matriz[1002][1002];//matriz relações
int vetor[1002];//vetor amizade

void zera(){
  int i, j;
  for(i = 0; i < 1002; i++){
    vetor[i] = 0;
  }
  for(i = 0; i < 1002;i++){
    for(j = 0; j < 1002;j++){
      matriz[i][j] = 0;
    }
  }
}

void mata_amizades(int pessoa, int n){
  int i;
  for(i = 1; i < n+1; i++){
    if(matriz[i][pessoa]){
      vetor[i]--;
      matriz[i][pessoa] = 0;
      matriz[pessoa][i] = 0;
    }
  }
}

int main(){
  int n, m, k;//num de pessoas, relações e min amigos
  int print_0, aux, i;//auxiliares
  int a, b;//pessoas relacionadas
  while(scanf("%d %d %d", &n, &m, &k) != EOF){
    zera();
    for(i = 0; i < m; i++){
      scanf("%d %d", &a, &b);
      matriz[a][b]++;
      matriz[b][a]++;
      if(matriz[a][b] == 1){
        vetor[a]++;
        vetor[b]++;
      }
    }

    for(i = 1; i < n+1; i++){
      if(vetor[i] < k && vetor[i] > 0){
        mata_amizades(i, n);
        vetor[i] = 0;
        i = 1;
      }
    }
    aux = 1;
    print_0 = 1;
    for(i = 1; i <= n; i++){
      if(vetor[i] >= k && aux){
        printf("%d", i);
        aux = 0;
        print_0 = 0;
      }
      else if(vetor[i] >= k){
        printf(" %d", i);
      }
    }
    if(print_0 == 1){
      printf("0");
    }
    printf("\n");
  }
  return 0;
}
