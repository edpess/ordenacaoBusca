#include <stdlib.h>
#include "sort.h"

void
mergeSort (long int *vet, long int inicio, long int fim)
{				// merge sort crescente

  if (inicio == fim)
    {
      return;
    }

  long int m = (inicio + fim) / 2;

  mergeSort (vet, inicio, m);
  mergeSort (vet, m + 1, fim);

  long int k = 0;
  long int i = inicio;
  long int j = m + 1;
  //A linha abaixo cria um novo vetor auxiliar
  long int *t = (long int *) malloc (sizeof (long int) * (fim - inicio + 1));

  while (i < m + 1 || j < fim + 1)
    {
      if (i == m + 1)
	{
	  *(t + k) = *(vet + j);
	  j++;
	  k++;
	}
      else
	{
	  if (j == fim + 1)
	    {
	      *(t + k) = *(vet + i);
	      i++;
	      k++;
	    }
	  else
	    {
	      if (*(vet + i) < *(vet + j))
		{
		  *(t + k) = *(vet + i);
		  i++;
		  k++;
		}
	      else
		{
		  *(t + k) = *(vet + j);
		  j++;
		  k++;
		}
	    }
	}
    }
  //Este laco copia o vetor auxiliar no vetor principal
  for (i = inicio; i <= fim; i++)
    {
      *(vet + i) = *(t + i - inicio);
    }
}

void
mergeSortD (long int *vet, long int inicio, long int fim)
{				// merge sort decrescente

  if (inicio == fim)
    {
      return;
    }

  long int m = (inicio + fim) / 2;

  mergeSortD (vet, inicio, m);
  mergeSortD (vet, m + 1, fim);

  long int k = 0;
  long int i = inicio;
  long int j = m + 1;
  long int *t = (long int *) malloc (sizeof (long int) * (fim - inicio + 1));

  while (i < m + 1 || j < fim + 1)
    {

      if (i == m + 1)
	{
	  *(t + k) = *(vet + j);
	  k++;
	  j++;
	}
      else
	{
	  if (j == fim + 1)
	    {
	      *(t + k) = *(vet + i);
	      i++;
	      k++;
	    }
	  else
	    {
	      if (*(vet + i) > *(vet + j))
		{
		  *(t + k) = *(vet + i);
		  i++;
		  k++;
		}
	      else
		{
		  *(t + k) = *(vet + j);
		  j++;
		  k++;
		}
	    }
	}
    }
  //Este laco copia o vetor auxiliar no vetor principal
  for (i = inicio; i <= fim; i++)
    {
      *(vet + i) = *(t + i - inicio);
    }
}
