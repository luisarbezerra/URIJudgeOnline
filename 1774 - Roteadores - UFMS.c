#include <stdio.h>
#include <stdlib.h>

int menor_chave(int chave[], int eh_menor[], int n_vertice){
    int minimo = 999999;
    int minimo_indice, i;

    for (i=0; i< n_vertice; i++){
        if(eh_menor[i]  == -1 && chave[i] < minimo){
          minimo = chave[i];
          minimo_indice = i;
        }
    }
    return minimo_indice;
}

void PRIM (int n_vertice, int grafo [n_vertice][n_vertice]) {

    int pai[n_vertice];
    int chave[n_vertice];
    int eh_menor[n_vertice]; // -1 é falso, true é 1
    int i,j;

    for (i=0; i<n_vertice; i++){
        chave[i] = 999999;
        eh_menor[i] = -1;
    }

    chave[0]=0;
    pai[0] = -1;

    for(i=0; i<n_vertice-1; i++){
        int minimo = menor_chave(chave, eh_menor, n_vertice);
        eh_menor[minimo] = 1;

        for (j=0; j<n_vertice; j++){
          if (grafo[minimo][j] && eh_menor[j] == -1 && grafo[minimo][j] < chave[j]){
              pai[j] = minimo;
              chave[j]= grafo[minimo][j];

          }
        }

    }

    int resultado = 0;

    for(i=1; i<n_vertice; i++){

        resultado = resultado + grafo[i][pai[i]];
    }

    printf("%d\n", resultado);
}

int main () {
    int n_vertice, n_aresta;
    scanf( "%d %d", &n_vertice, &n_aresta);

    int grafo [n_vertice][n_vertice];

    int i,j;

    for (i=0; i<n_vertice; i++){
        for (j=0; j<n_vertice; j++){
            grafo [i][j] = 999999;
        }
    }

    for (i=0; i<n_aresta; i++){
        int verticeA, verticeB, peso;
        scanf("%d %d %d", &verticeA, &verticeB, &peso);

        grafo[verticeA-1][verticeB-1] = peso;
        grafo[verticeB-1][verticeA-1] = peso;
    }

    PRIM(n_vertice, grafo);

    return 0;
  }
