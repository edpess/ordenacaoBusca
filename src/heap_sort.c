#include "sort.h"

void
heapSort (long int *vet, long int n)
{				// heap sort crescente

  register long int i = n / 2;
  long int t, pai, filho;

  for (;;)
    {
      if (i > 0)
	{
	  i--;
	  t = *(vet + i);
	}
      else
	{
	  n--;
	  if (n == 0)
	    {
	      return;
	    }
	  t = *(vet + n);
	  *(vet + n) = *vet;
	}
      pai = i;
      filho = 2 * pai + 1;

      while (filho < n)
	{

	  if (filho + 1 < n && *(vet + filho + 1) > *(vet + filho))
	    {
	      filho++;
	    }

	  if (*(vet + filho) > t)
	    {
	      *(vet + pai) = *(vet + filho);
	      pai = filho;
	      filho = 2 * pai + 1;
	    }
	  else
	    {
	      break;
	    }
	}

      *(vet + pai) = t;
    }
}

void
heapSortD (long int *vet, long int n)
{				//head sort decrescente

  long int i = n / 2;
  long int troca;
  for (;;)
    {

      if (i > 0)
	{
	  i--;
	  troca = *(vet + i);
	}
      else
	{
	  n--;
	  if (n == 0)
	    {
	      return;
	    }
	  troca = *(vet + n);
	  *(vet + n) = *vet;
	}

      long int pai = i;
      long int filho = 2 * pai + 1;

      while (filho < n)
	{
	  if (filho + 1 < n && *(vet + filho + 1) < *(vet + filho))
	    {
	      filho++;
	    }

	  if (*(vet + filho) < troca)
	    {
	      *(vet + pai) = *(vet + filho);
	      pai = filho;
	      filho = 2 * pai + 1;
	    }
	  else
	    {
	      break;
	    }
	}
      *(vet + pai) = troca;
    }
}
