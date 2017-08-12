#include <stdio.h>
#include <stdlib.h>

float busca_binaria(int soma_area_total, int vetor_area_barras[], int N, float altura_base, float altura_max){

    float altura_de_corte = (altura_base + altura_max)/2.0;
    float area_de_corte = 0.0;
    int i;
    for(i = 0; i < N; i++) {
        if((float)vetor_area_barras[i] > altura_de_corte) {
            area_de_corte = area_de_corte +  ((float)vetor_area_barras[i] - altura_de_corte);
        }
    }

    if((altura_max - altura_base) < 0.000001) {
      return altura_de_corte;
    } else if (area_de_corte > soma_area_total) {
      return busca_binaria(soma_area_total, vetor_area_barras, N, altura_de_corte, altura_max);
    } else if(area_de_corte < soma_area_total) {
        return busca_binaria(soma_area_total, vetor_area_barras, N, altura_base, altura_de_corte);
    }
}

int main() {

    int N, A;//quantidade de tiras e a área resultante esperada.
    int i;
    float altura_max = 0.0;
    int soma_area_total = 0; //para cada caso, uma soma de area nova.


    while(scanf("%d %d", &N, &A) != 0 && N != 0){
        altura_max = 0.0;
        soma_area_total = 0;
        int vetor_area_barras[N];

        for (i = 0; i < N; i++){
            scanf("%d", &vetor_area_barras[i]);
            soma_area_total = soma_area_total + (float)vetor_area_barras[i];
            if ((float)vetor_area_barras[i] > altura_max){
                altura_max = (float)vetor_area_barras[i];
            }
        }

        if(soma_area_total == A){
            printf(":D\n"); //área total = área corte.
        } else if (soma_area_total < A){
            printf("-.-\n"); //área total menor que a área corte.
        } else {
            int aux = A;
            printf("%.4f\n", busca_binaria(aux, vetor_area_barras, N, 0.0, altura_max));
        }
    }

    return 0;
}
