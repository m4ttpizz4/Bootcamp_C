//Calcular a nota de 10 alunos durante o ano, exibir na tela de forma organizada as notas: AV1, AVD, AV2, AV3 e a média final.
//Bibliotecas:
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//int main, locale e variáveis:
void main(){
setlocale(LC_ALL, "Portuguese");
int i, AV1[10], AV2[10], AV3[10], MED[10], aluno[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//Interação:
printf("|----------------------------|\nSistema de atribuição de notas:\n\n");
for(i=0; i<=9; i++){
	printf("Insira a AV1 do %iº aluno:\n\n", aluno[i]);
	scanf("%i", &AV1[i]);
	printf("Insira a AV2 do %iº aluno:\n\n", aluno[i]);
	scanf("%i", &AV2[i]);
	printf("Insira a AV3 do %iº aluno:\n\n", aluno[i]);
	scanf("%i", &AV3[i]);
	MED[i]=(AV1[i]+AV2[i]+AV3[i])/3;
	printf("|-------------------------------------|\n");
}
//Resultados:
printf("[Resultado das notas dos alunos:]\n");
printf("	AV1	|	AV2	|	AV3	|	MED\n");
printf("01-	%i	|	%i	|	%i	|	%i\n", AV1[0], AV2[0], AV3[0], MED[0]);
printf("02-	%i	|	%i	|	%i	|	%i\n", AV1[1], AV2[1], AV3[1], MED[1]);
printf("03-	%i	|	%i	|	%i	|	%i\n", AV1[2], AV2[2], AV3[2], MED[2]);
printf("04-	%i	|	%i	|	%i	|	%i\n", AV1[4], AV2[4], AV3[4], MED[4]);
printf("06-	%i	|	%i	|	%i	|	%i\n", AV1[5], AV2[5], AV3[5], MED[5]);
printf("07-	%i	|	%i	|	%i	|	%i\n", AV1[6], AV2[6], AV3[6], MED[6]);
printf("08-	%i	|	%i	|	%i	|	%i\n", AV1[7], AV2[7], AV3[7], MED[7]);
printf("09-	%i	|	%i	|	%i	|	%i\n", AV1[8], AV2[8], AV3[8], MED[8]);
printf("10-	%i	|	%i	|	%i	|	%i\n", AV1[9], AV2[9], AV3[9], MED[9]);
//Finalização:
system("pause");
return (0);
}
