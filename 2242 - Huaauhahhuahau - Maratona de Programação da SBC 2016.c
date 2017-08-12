#include <stdio.h>

int main() {

    char risada[51]="";
    scanf("%s", &risada);

    char vogais[51]="";
    int i, j=0;

    for (i=0; i<51; i++){
        if (risada[i] == 'a' || risada [i] == 'e' || risada [i] == 'i'|| risada [i] == 'o'|| risada [i] == 'u') {
            vogais[j] = risada[i];
            j++;
        }
    }

    vogais[j]='\0';
    i=0;
    j--;

    char vogaisinversa[51] = "";
    int k=j;

    for (i=0; i<=k; i++){
        vogaisinversa[i] = vogais[j];
        j--;
    }

    if (strncmp(vogais, vogaisinversa) == 0){
        printf("S\n");
    } else {
        printf("N\n");
    }

    return 0;
}
