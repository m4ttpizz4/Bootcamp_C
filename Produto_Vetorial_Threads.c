#include <stdio.h>
#include <pthread.h>

#define TAMANHO_VETOR 1000
#define NUM_THREADS 4

int vetor1[TAMANHO_VETOR];
int vetor2[TAMANHO_VETOR];

typedef struct {
    int inicio;
    int fim;
} Intervalo;

int ProdutoVetorial(int inicio, int fim) {
    int soma = 0;
    for (int i = inicio; i < fim; i++) {
        soma += vetor1[i] * vetor2[i];
    }
    return soma;
}
int soma_parcial[NUM_THREADS];

void* thread_func(void* arg) {
    Intervalo* intervalo = (Intervalo*)arg;
    int inicio = intervalo->inicio;
    int fim = intervalo->fim;
    int thread_id = intervalo - (Intervalo*)arg;
    soma_parcial[thread_id] = ProdutoVetorial(inicio, fim);
    pthread_exit(NULL);
}
int main() {
    // Inicializa os vetores com valores de exemplo
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        vetor1[i] = i + 1;
        vetor2[i] = i + 1;
    }

    pthread_t threads[NUM_THREADS];
    Intervalo intervalos[NUM_THREADS];
    int intervalo_tamanho = TAMANHO_VETOR / NUM_THREADS;

    // Cria as threads
    for (int i = 0; i < NUM_THREADS; i++) {
        intervalos[i].inicio = i * intervalo_tamanho;
        intervalos[i].fim = (i + 1) * intervalo_tamanho;
        pthread_create(&threads[i], NULL, thread_func, (void*)&intervalos[i]);
    }

    // Junta as threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Calcula a soma total
    int soma_total = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        soma_total += soma_parcial[i];
    }

    printf("Produto vetorial: %d\n", soma_total);

    return 0;
}