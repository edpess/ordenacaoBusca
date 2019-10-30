#include <stdio.h>
#include <time.h>
#include "search.h"
#include "util.h"

int
buscaSequencial (long int *vet)
{				//busca sequencial

  int i, z;
  clock_t inicio, fim = MAX - 1;

  printf ("\n\nQue numero deseja procurar?\n");
  scanf ("%d", &z);

  inicio = clock ();
  for (i = 0; i < MAX; i++)
    {
      if (vet[i] == z)
	{
	  fim = clock ();
	  return i
	    &&
	    printf
	    ("\n\nA Busca Sequencial achou o numero %d em um vetor de %d posições em %ld ms\n\n",
	     z, MAX, (fim - inicio));
	}
    }
  printf ("\n\nNumero não encontrado\n\n");
  return -1;

}


int
buscaBinaria (long int *vet)
{				//busca binaria

  long int inicio = 0;
  long int fim = MAX - 1;

  int i = 0;
  int x = 0;

  printf ("\n\nQue numero deseja procurar?\n");
  scanf ("%d", &x);

  while (inicio <= fim)
    {
      i = (inicio + fim) / 2;

      if (vet[i] == x)
	{
	  //printf("\nAchou %d", x);
	  printf
	    ("\n\nA Busca Binaria achou o numero %d em um vetor de %d posições em %ld ms\n\n",
	     x, MAX, (fim - inicio));
	  return x;
	}
      if (vet[i] < x)
	inicio = i + 1;
      else
	fim = i - 1;
    }
  printf ("\n\nNumero não encontrado\n\n");

  return -1;
}
