//bibliotecas:
#include <stdio.h>
#include <pthread.h>
#define TAMANHO_VETOR 10
#define NUM_THREADS 4

int vetor1[TAMANHO_VETOR], vetor2[TAMANHO_VETOR], soma_parcial[NUM_THREADS];

void* ProdutoVetorial(void* arg) {
    int thread_id = *(int*)arg;
    int inicio = thread_id * (TAMANHO_VETOR / NUM_THREADS);
    int fim = (thread_id + 1) * (TAMANHO_VETOR / NUM_THREADS);
    int soma = 0;
    
    for (int i = inicio; i < fim; i++) {
        soma += vetor1[i] * vetor2[i];
    }
    
    soma_parcial[thread_id] = soma;
    pthread_exit(NULL);
}

int main() {
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        vetor1[i] = i + 1;
        vetor2[i] = i + 1;
    }
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, ProdutoVetorial, &thread_ids[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    int soma_total = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        soma_total += soma_parcial[i];
    }

    printf("Produto vetorial: %d\n", soma_total);
    return 0;
}