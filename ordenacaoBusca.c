/* Projeto final da disciplina de Estrutura de Dados
 * 
 * Docente: Profª Ceres Germana
 * Discentes Ed Carlos Pessoa
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 500 //Define o tamanho maximo do vetor

void setVet( long int *vet ); //Preenche o vetor com valores aleatorios
void printVet( long int *vet );
void mergeSort( long int *vet, long int inicio, long int fim );
void mergeSortD( long int *vet, long int inicio, long int fim );
void heapSort( long int *vet, long int n);
void heapSortD( long int *vet, long int n);
int buscaBinaria (long int *vet); //, long int inicio, long int fim, int x
int buscaSequencial(long int *vet);

int main () {
    long int vet[MAX];
    clock_t inicio, fim;
    int opcao; //n = 0,
    
    do{

		printf("\n\n\t\tMENU\n\n");
		printf("1 - Busca Binaria no Vetor Ordenado\n");
		printf("2 - Busca Sequencial no Vetor não Ordenado\n");
		printf("3 - Ordenação Crescente Merge Sort\n");
		printf("4 - Ordenação Decrescente Merge Sort\n");
		printf("5 - Ordenação Crescente Heap Sort\n");
		printf("6 - Ordenação Decrescente Heap Sort\n");
		printf("7 - Sair\n");
		printf("\nEscolha a opcao: ");
		scanf("%d", &opcao);
		
		if(opcao < 1 || opcao > 7){
			printf("\nOpcao Invalida\n\n");
		}
	
	
	if(opcao == 1){ //busca binaria ordenada
		
		//clock_t inicio, fim;
		setVet(&vet[0]);
		inicio = clock();
		mergeSort(&vet[0], 0, MAX - 1);
		buscaBinaria(vet);
		fim = clock();
		
		printVet(&vet[0]); //impressão para teste de visualização
				
	}	
	
	if(opcao == 2){ //busca sequencial não ordenada
		
		setVet(&vet[0]);
		inicio = clock();
		buscaSequencial(vet);
		fim = clock();	
		
		printVet(&vet[0]); //impressão para teste de visualização
		
	}
	
	if(opcao == 3){ //merge sort crescente
		
		setVet(&vet[0]);
		inicio = clock();
		mergeSort(&vet[0], 0, MAX - 1);
		fim = clock();
		printVet(&vet[0]);
		printf("\n\nO metodo Merge Sort ordenou o vetor de %d posicoes em %ld ms",
                  MAX, ( fim - inicio ));
		
		return 0;
	}
	
	if(opcao == 4){ //merge sort decrescente
		
	    setVet( &vet[0] );
		inicio = clock();
		mergeSortD( &vet[0], 0, MAX - 1 );
		fim = clock();
		printVet( &vet[0] );
		printf("\n\nO metodo Merge Sort ordenou o vetor de %d posicoes em %ld ms", 
                         MAX, ( fim - inicio ) );
		return 0;
	}
	
	if(opcao == 5){ //heapSort crescente
	
		setVet(&vet[0]);
		inicio = clock();
		heapSort(&vet[0], MAX );
		fim = clock();
		printVet(&vet[0]);
			printf("\n\nO metodo Heap Sort ordenou o vetor de %d posicoes em %ld ms",
                         MAX, ( fim - inicio ) );
    return 0;
		
	}
	
	if(opcao == 6){ //heapSort decrescente 
	
	    setVet( &vet[0] );
		inicio = clock();
		heapSortD( &vet[0], MAX );
		fim = clock();
		printVet( &vet[0] );
		printf("\n\nO metodo Heap Sort ordenou o vetor de %d posicoes em %ld ms.",
                  MAX, ( fim - inicio ) );
   
		return 0;
	}
	
}while(opcao != 7);
	
}


		
int buscaSequencial(long int *vet){ //busca sequencial
	
	int i, z;
	clock_t inicio, fim = MAX - 1;
			
	printf("\n\nQue numero deseja procurar?\n");
    scanf("%d", &z);  
	
		inicio = clock();	
	for (i = 0; i < MAX; i++) {
		if (vet[i] == z) {
			fim = clock();
    return i && printf("\n\nA Busca Sequencial achou o numero %d em um vetor de %d posições em %ld ms\n\n"
																			   ,z ,MAX, ( fim - inicio ));             
		}         
	}
		printf("\n\nNumero não encontrado\n\n");
    return -1;

 }


int buscaBinaria (long int *vet) { //busca binaria
      
   long int inicio = 0;
   long int fim = MAX -1;
  
   int i=0;
   int x=0;                       
   
   printf("\n\nQue numero deseja procurar?\n");
   scanf("%d", &x);  
   
   while (inicio <= fim)
   {	
	   i = (inicio + fim)/2;	
	   
		if (vet[i] == x){
			//printf("\nAchou %d", x);
			printf("\n\nA Busca Binaria achou o numero %d em um vetor de %d posições em %ld ms\n\n",
                  x, MAX, ( fim - inicio ));
			return x;}
		if (vet[i] < x)
			inicio = i+1;
			else 
				fim = i-1;}
			printf("\n\nNumero não encontrado\n\n");
	
	return -1;
}	
   
void setVet( long int *vet ) { //preenche o vetor com valores aleatorios
     
     register long int i;
     
     srand( time( NULL ) );
     for( i = 0; i < MAX; i++ ) {
          *( vet + i ) = rand()%(MAX-1)+1;
     }
}

void printVet( long int *vet ) { //imprime o vetor 
     
     register long int i;
     
     for( i = 0; i < MAX; i++ ) {
		 if (i % 10 == 0){
		printf("\n");
		}
          printf("  %ld\t", *( vet + i ));
     }
}

void mergeSort( long int *vet, long int inicio, long int fim ) { // merge sort crescente
     
     if( inicio == fim ) { return; }
     
     long int m = ( inicio + fim ) / 2;
     
     mergeSort( vet, inicio, m );
     mergeSort( vet, m + 1, fim);
     
     long int k = 0;
     long int i = inicio;
     long int j = m + 1;
     //A linha abaixo cria um novo vetor auxiliar
     long int *t = ( long int * ) malloc( sizeof (long int) * ( fim - inicio + 1) );
     
     while ( i < m + 1 || j < fim + 1 ) {
           if( i == m + 1 ) {
               *( t + k ) = *( vet + j );
               j++;
               k++;
           }else{
                 if ( j == fim + 1 ) {
                      *( t + k ) = *( vet + i );
                      i++;
                      k++;
                 }else{
                       if( *( vet + i ) < *( vet + j ) ) {
                           *( t + k ) = *( vet + i );
                           i++;
                           k++;
                       }else{
                             *( t + k ) = *( vet + j );
                             j++;
                             k++;
                       }
                 }
           }
     }
     //Este laco copia o vetor auxiliar no vetor principal
     for( i = inicio; i <= fim; i++ ){
          *( vet +  i ) = *( t + i - inicio );
     }
}

void mergeSortD( long int *vet, long int inicio, long int fim ) { // merge sort decrescente
     
     if ( inicio == fim ) {
          return;
     }
     
     long int m = ( inicio + fim ) / 2;
     
     mergeSortD( vet, inicio, m );
     mergeSortD( vet, m + 1, fim );
     
     long int k = 0;
     long int i = inicio;
     long int j = m + 1;
     long int *t = ( long int * ) malloc( sizeof( long int ) * ( fim - inicio + 1) );
     
     while( i < m + 1 || j < fim + 1 ) {
            
            if( i == m + 1 ) {
                *( t + k ) = *( vet + j );
                k++;
                j++;
            }else{
                  if( j == fim + 1 ) {
                      *( t + k ) = *( vet + i );
                      i++;
                      k++;
                  }else{
                        if( *( vet + i ) > *( vet + j ) ) {
                            *( t + k ) = *( vet + i );
                            i++;
                            k++;
                        }else{
                              *( t + k ) = *( vet + j );
                              j++;
                              k++;
                        }
                  }
            }
     }
     //Este laco copia o vetor auxiliar no vetor principal
     for( i = inicio; i <= fim; i++ ) {
          *( vet + i ) = *( t + i - inicio );
     }
} 

void heapSort( long int *vet, long int n ) { // heap sort crescente
     
     register long int i = n / 2;
     long int t, pai, filho;
     
     for( ;; ) {
          if( i > 0 ) {
              i--;
              t = *( vet + i );
          }else{
                n--;
                if ( n == 0 ) { return; }
                t = *( vet + n );
                *( vet + n ) = *vet;
          }
          pai = i;
          filho = 2 * pai + 1;
          
          while( filho < n ) {
                 
                 if( filho + 1 < n && *( vet + filho + 1 ) > *( vet + filho ) ){
                     filho++;
                 }
                 
                 if( *( vet + filho ) > t ) {
                     *( vet + pai ) = *( vet + filho );
                     pai = filho;
                     filho = 2 * pai + 1;
                 }else{
                       break;
                 }
          }
          
          *( vet + pai ) = t;
     }
}

void heapSortD( long int *vet, long int n ) { //head sort decrescente
     
     long int i = n / 2;
     long int troca;
     for( ; ; ) {
          
          if( i > 0 ) {
              i--;
              troca = *( vet + i );
          }else{
              n--;
              if( n == 0 )  {  return;  }
              troca = *( vet + n );
              *( vet + n ) = *vet;
          }
          
          long int pai = i;
          long int filho = 2 * pai + 1;
          
          while( filho < n ) {
                 if( filho + 1 < n && *( vet + filho + 1 ) < *( vet + filho ) ) {
                     filho++;
                 }
                 
                 if( *( vet + filho ) < troca ) {
                     *( vet + pai ) = *( vet + filho );
                     pai = filho;
                     filho = 2 * pai + 1;
                 }else{
                     break;
                 }
          }
          *( vet + pai ) = troca;
     }
}
