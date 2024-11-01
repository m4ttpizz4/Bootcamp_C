//bibliotecas:
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//função main:
int main() {
	//variáveis:
    time_t tempo;
    struct tm * info_tempo;
    char buffer[10];

	//obtém o tempo
    time(&tempo);
    info_tempo = localtime(&tempo); //converte o tempo armazenado para a hora local

	//formata a hora em hh:mm AM/PM e armazena no buffer:
    strftime(buffer, sizeof(buffer), "%I:%M %p", info_tempo);
    printf("Hora atual: %s\n", buffer); //printa a conversão e a formatação feita pelo programa

	//pausa para o usuário apertar uma tecla e encerrar o programa:
	system('pause'); 
    return 0;
}