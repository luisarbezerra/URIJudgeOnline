#include <stdio.h>
#include <stdlib.h>

typedef struct SPELL{
  int dano;
  int mana;
}SPELL;

int min(int a, int b) {
    return (a < b)? a : b;
}

int demogorgon(int vida, SPELL spell[], int n_feiticos){
    int i, pesinho;
    int k[n_feiticos+1][vida+1];

    for ( i = 0; i <= n_feiticos; i++ ){
        for ( pesinho = 0; pesinho <= vida; pesinho++ ){
            if ( i == 0 ){
               k[i][pesinho] = 9999999;
            }
            else if( pesinho == 0) {
               k[i][pesinho] = 0;
            } else if ( spell[i-1].dano >= pesinho ) {
                 k[i][pesinho] = min(spell[i-1].mana,  k[i-1][pesinho]);
            } else if(spell[i-1].dano < pesinho){
            //    if(k[i-1][pesinho] < 9999999){
            //      k[i][pesinho] = k[i-1][pesinho];
            //    }
              //  else if(k[i-1][pesinho] >= 9999999){
                  k[i][pesinho] = min(spell[i-1].mana + k[i-1][pesinho - spell[i-1].dano], k[i-1][pesinho]);
              //  }
            }
        }
    }
/*    for(i = 0; i <= n_feiticos; i++){
      for(pesinho = 0; pesinho <= vida; pesinho++){
        printf("%d ", k[i][pesinho]);
      }
      printf("\n");
    }
*/
    return k[n_feiticos][vida];
}

int main(){

    int n_feiticos, mana_total = 0, dano_total, vida, i;

    while (scanf("%d %d", &n_feiticos, &vida) != EOF){
        dano_total = 0;
        SPELL spell[n_feiticos];

        for (i=0; i<n_feiticos; i++){
            scanf("%d %d", &spell[i].dano, &spell[i].mana);
            dano_total = dano_total + spell[i].dano;
        }
        if (dano_total < vida){
            printf("-1\n");
        } else {
            mana_total = demogorgon(vida, spell, n_feiticos);
            printf("%d\n", mana_total);
        }
    }

    return 0;
}
