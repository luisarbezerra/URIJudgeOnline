#include <stdio.h>
#include <string.h>

int main()
{
  while(1){
    int n;
    scanf("%d", &n);

    if(n == 0) break;

    char palavras[n][101];

    int i;
    for(i = 0; i < n; i++)
    {
      scanf("%s", palavras[i]);
    }

    int j;
    int encontrou = 0;

    for(i = 0; i < n && encontrou == 0; i++)
    {
      for(j = 0; j < n && encontrou == 0; j++)
      {
        if(i != j)
        {
          char * pch;
          pch = strstr (palavras[i],palavras[j]);

          if(pch != NULL && pch == palavras[i])
          {
            encontrou = 1;
          }
        }
      }
    }

    if(encontrou == 1){
      printf("Conjunto Ruim\n");
    }
    else{
      printf("Conjunto Bom\n");
    }

  }

  return 0;
}
