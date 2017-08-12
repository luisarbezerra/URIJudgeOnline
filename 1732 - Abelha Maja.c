#include <stdio.h>
#include <stdlib.h>

int nivel_circulo(int num_favo){
    int k = 1;
    while (1){
        if((1 + 3*k*k - 3*k) >= num_favo){
            break;
        }
        k++;
    }
    return k;
}

int main()
{
    int num_favo;
    while (scanf("%d", &num_favo) == 1){
        int circulo = nivel_circulo(num_favo);
        int indice = (1 + 3*circulo*circulo - 3*circulo - num_favo );
        int x = circulo -1;
        int y = 0;

        int p = circulo -1;
        int andando_x = 1;
        int andando_y = -1;

        int k;
        for(k = 0; k < indice; k++){

            if(( k % p ) == 0) {
                if(andando_x == 0 && andando_y == -1){
                    andando_x = -1;
                    andando_y = 0;
                }
                else if(andando_x == 0 && andando_y == +1){
                    andando_x = +1;
                    andando_y = 0;
                }
                else if(andando_x == +1 && andando_y == 0){
                    andando_x = +1;
                    andando_y = -1;
                }
                else if(andando_x == +1 && andando_y == -1){
                    andando_x = 0;
                    andando_y = -1;
                }
                else if(andando_x == -1 && andando_y == 0){
                    andando_x = -1;
                    andando_y = +1;
                }
                else if(andando_x == -1 && andando_y == +1){
                    andando_x = 0;
                    andando_y = +1;
                }
            }

            x = x + andando_x;
            y = y + andando_y;
        }

        printf("%d %d\n", x, y);
    }
}
