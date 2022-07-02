//Bibliotecas:
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Função main, locale e variáveis:
void main(){
setlocale(LC_ALL,"Portuguese");
int qnt, tipo, casquinha=0, recheada=0, pote=0, sabor, baunilha=0, chocolate=0, misto=0, i;
float valor;
//Funcionamento:
printf("|------------------------------------------|\n");
printf("	[Sorveteria de M4ttPizz4<3]\n\n");
printf("Insira a quantidade de sorvetes que você deseja e pressione a tecla 'enter':\n");
scanf("%i", &qnt);
for(i=1; i<=qnt; i++){
printf("\n|------------------------------------------|\n");
//Tipos:
printf("Selecione o tipo do sorvete de acordo com seu número correspondente:\n1.Casquinha.(R$3,00)\n2.Casquinha com recheio de chocolate.(R$3,50)\n3.Pote.(R$8,00)\n");
scanf("%i", &tipo);
if(tipo==1){
casquinha++;
}
else if(tipo==2){
recheada++;
}
else if(tipo==3){
pote++;
}
//Sabores:
printf("Selecione o sabor do sorvete:\n1.Baunilha.\n2.Chocolate.\n3.Misto(1+2).\n");
scanf("%i", &sabor);
if(sabor==1){
baunilha++;
}
else if(sabor==2){
chocolate++;
}
else if(sabor==3){
misto++;
}
}
valor=(3.00*casquinha)+(3.50*recheada)+(8.00*pote);
printf("O pedido é:\n\nQuantidade de sorvetes: %i\n\nSabores:\nTipos:\nCasquinha: %i\nCasquinha recheada: %i\nPote: %i\n\nSabores:\nBaunilha: %i\nChocolate: %i\nMisto: %i\n\nValor: %.2f\n\n", qnt, casquinha, recheada, pote, baunilha, chocolate, misto, valor);
//Finalizações:
system("pause");
return(0);
}
