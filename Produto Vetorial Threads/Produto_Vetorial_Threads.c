#include <stdio.h>
#include <pthread.h>
#define TAMANHO_VETOR 1000
#define NUM_THREADS 4

int vetor1[TAMANHO_VETOR], vetor2[TAMANHO_VETOR], soma_parcial[NUM_THREADS];

void* ProdutoVetorial(void* arg)
{
    int thread_id = *(int*)arg;  // Obtém o ID da thread
    int inicio = thread_id * (TAMANHO_VETOR / NUM_THREADS);  // Calcula o índice inicial
    int fim = (thread_id + 1) * (TAMANHO_VETOR / NUM_THREADS);  // Calcula o índice final
    int soma = 0;  // Inicializa a soma
    
    for (int i = inicio; i < fim; i++) // Loop para calcular o produto
    {  
        soma += vetor1[i] * vetor2[i];  // Soma o produto dos elementos
    }
    soma_parcial[thread_id] = soma;  // Armazena a soma parcial
    pthread_exit(NULL);  // Encerra a thread
}

int main()
{
    for (int i = 0; i < TAMANHO_VETOR; i++)
    {  // Inicializa os vetores
        vetor1[i] = i + 1;
        vetor2[i] = i + 1;
    }
    pthread_t threads[NUM_THREADS];  // Array para armazenar threads
    int thread_ids[NUM_THREADS];  // Array para IDs das threads

    for (int i = 0; i < NUM_THREADS; i++) // Cria as threads
    {  
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, ProdutoVetorial, &thread_ids[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++) // Espera as threads terminarem
    {  
        pthread_join(threads[i], NULL);
    }
    int soma_total = 0;  // Inicializa a soma total
    for (int i = 0; i < NUM_THREADS; i++) // Calcula a soma total
    {  
        soma_total += soma_parcial[i];
    }

    printf("Produto vetorial: %d\n", soma_total);  // Imprime o resultado
    return 0;
}