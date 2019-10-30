/* Projeto final da disciplina de Estrutura de Dados
 *
 * Docente: Profª Ceres Germana
 * Discentes Ed Carlos Pessoa
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util.h"
#include "search.h"
#include "sort.h"

int
main ()
{
  long int vet[MAX];
  clock_t inicio, fim;
  int opcao;			//n = 0,

  do
    {

      printf ("\n\n\t\tMENU\n\n");
      printf ("1 - Busca Binaria no Vetor Ordenado\n");
      printf ("2 - Busca Sequencial no Vetor não Ordenado\n");
      printf ("3 - Ordenação Crescente Merge Sort\n");
      printf ("4 - Ordenação Decrescente Merge Sort\n");
      printf ("5 - Ordenação Crescente Heap Sort\n");
      printf ("6 - Ordenação Decrescente Heap Sort\n");
      printf ("7 - Sair\n");
      printf ("\nEscolha a opcao: ");
      scanf ("%d", &opcao);

      if (opcao < 1 || opcao > 7)
	{
	  printf ("\nOpcao Invalida\n\n");
	}


      if (opcao == 1)
	{			//busca binaria ordenada

	  //clock_t inicio, fim;
	  setVet (&vet[0]);
	  inicio = clock ();
	  mergeSort (&vet[0], 0, MAX - 1);
	  buscaBinaria (vet);
	  fim = clock ();

	  printVet (&vet[0]);	//impressão para teste de visualização

	}

      if (opcao == 2)
	{			//busca sequencial não ordenada

	  setVet (&vet[0]);
	  inicio = clock ();
	  buscaSequencial (vet);
	  fim = clock ();

	  printVet (&vet[0]);	//impressão para teste de visualização

	}

      if (opcao == 3)
	{			//merge sort crescente

	  setVet (&vet[0]);
	  inicio = clock ();
	  mergeSort (&vet[0], 0, MAX - 1);
	  fim = clock ();
	  printVet (&vet[0]);
	  printf
	    ("\n\nO metodo Merge Sort ordenou o vetor de %d posicoes em %ld ms",
	     MAX, (fim - inicio));

	  return 0;
	}

      if (opcao == 4)
	{			//merge sort decrescente

	  setVet (&vet[0]);
	  inicio = clock ();
	  mergeSortD (&vet[0], 0, MAX - 1);
	  fim = clock ();
	  printVet (&vet[0]);
	  printf
	    ("\n\nO metodo Merge Sort ordenou o vetor de %d posicoes em %ld ms",
	     MAX, (fim - inicio));
	  return 0;
	}

      if (opcao == 5)
	{			//heapSort crescente

	  setVet (&vet[0]);
	  inicio = clock ();
	  heapSort (&vet[0], MAX);
	  fim = clock ();
	  printVet (&vet[0]);
	  printf
	    ("\n\nO metodo Heap Sort ordenou o vetor de %d posicoes em %ld ms",
	     MAX, (fim - inicio));
	  return 0;

	}

      if (opcao == 6)
	{			//heapSort decrescente

	  setVet (&vet[0]);
	  inicio = clock ();
	  heapSortD (&vet[0], MAX);
	  fim = clock ();
	  printVet (&vet[0]);
	  printf
	    ("\n\nO metodo Heap Sort ordenou o vetor de %d posicoes em %ld ms.",
	     MAX, (fim - inicio));

	  return 0;
	}

    }
  while (opcao != 7);

}
