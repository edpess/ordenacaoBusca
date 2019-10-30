#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util.h"

void
setVet (long int *vet)
{				//preenche o vetor com valores aleatorios

  register long int i;

  srand (time (NULL));
  for (i = 0; i < MAX; i++)
    {
      *(vet + i) = rand () % (MAX - 1) + 1;
    }
}

void
printVet (long int *vet)
{				//imprime o vetor

  register long int i;

  for (i = 0; i < MAX; i++)
    {
      if (i % 10 == 0)
	{
	  printf ("\n");
	}
      printf ("  %ld\t", *(vet + i));
    }
}
