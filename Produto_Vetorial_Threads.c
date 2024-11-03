#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>         // Inclui a biblioteca para utilizaC'C#o de threads

#define TAMANHO_VETOR 100   // Define o tamanho dos vetores como 1000
#define NUM_THREADS 4        // Define o nC:mero de threads como 4

int vetor1[TAMANHO_VETOR];   // Declara um vetor de inteiros chamado vetor1 com tamanho definido
int vetor2[TAMANHO_VETOR];   // Declara um vetor de inteiros chamado vetor2 com tamanho definido
int soma_parcial[NUM_THREADS]; // Declara um vetor para armazenar as somas parciais calculadas por cada thread

typedef struct {             // Define uma estrutura chamada Intervalo
	int inicio;              // Campo 'inicio' para armazenar o C-ndice inicial do intervalo
	int fim;                 // Campo 'fim' para armazenar o C-ndice final do intervalo
	int thread_id;           // Campo 'thread_id' para armazenar o ID da thread
} Intervalo;                 // Nome da estrutura C) Intervalo

void* ProdutoVetorial(void* arg) {  // FunC'C#o que serC! executada pelas threads
	Intervalo* intervalo = (Intervalo*)arg;  // Converte o argumento recebido em um ponteiro para Intervalo
	int soma = 0;              // Inicializa a variC!vel soma com zero
	for (int i = intervalo->inicio; i < intervalo->fim; i++) { // Loop para percorrer o intervalo
		soma += vetor1[i] * vetor2[i];  // Calcula o produto vetorial e acumula na variC!vel soma
	}
	soma_parcial[intervalo->thread_id] = soma; // Armazena a soma parcial no vetor correspondente
	pthread_exit(NULL);        // Termina a thread
}

int main() {                   // FunC'C#o principal do programa
	for (int i = 0; i < TAMANHO_VETOR; i++) {  // Inicializa os vetores com valores de exemplo
		vetor1[i] = i + 1;     // Atribui valores sequenciais ao vetor1
		vetor2[i] = i + 1;     // Atribui valores sequenciais ao vetor2
	}

	pthread_t threads[NUM_THREADS]; // Declara um vetor de threads
	Intervalo intervalos[NUM_THREADS]; // Declara um vetor de estruturas Intervalo
	int intervalo_tamanho = TAMANHO_VETOR / NUM_THREADS; // Calcula o tamanho de cada intervalo

	for (int i = 0; i < NUM_THREADS; i++) { // Loop para criar as threads
		intervalos[i].inicio = i * intervalo_tamanho; // Define o inC-cio do intervalo para a thread
		intervalos[i].fim = (i + 1) * intervalo_tamanho; // Define o fim do intervalo para a thread
		intervalos[i].thread_id = i; // Define o ID da thread
		pthread_create(&threads[i], NULL, ProdutoVetorial, (void*)&intervalos[i]); // Cria a thread
	}

	for (int i = 0; i < NUM_THREADS; i++) { // Loop para aguardar o tC)rmino das threads
		pthread_join(threads[i], NULL); // Aguarda o tC)rmino da thread
	}

	int soma_total = 0; // Inicializa a soma total com zero
	for (int i = 0; i < NUM_THREADS; i++) { // Loop para calcular a soma total
		soma_total += soma_parcial[i]; // Acumula as somas parciais na soma total
	}

	printf("Produto vetorial: %d\n", soma_total); // Imprime o resultado do produto vetorial

	return 0;
}
