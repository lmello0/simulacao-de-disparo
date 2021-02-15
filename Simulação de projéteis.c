#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int menu;
	char inicio = 's';
	float v0, inclinacao, distancia, tamanho, gravidade = 9.81;  //Informa��es para c�lculos
	float alturaMaxima = 0, tempoTrajeto = 0, alcanceHorizontal = 0, angulo = 0; //Vari�veis de c�lculo
	float maiorAltura = 0, media = 0, divisaoMedia = 0, porcentagem = 0, disparo = 0, acerto=0;; //Estatisticas
	
	do{ //Apresenta��o
		printf("Simulador de lan�amento de proj�teis\n\n\tby Lucas Mello dos Santos\n\n");
		printf("Executar programa? (s/n)\n");
		scanf(" %c", &inicio);
		printf("\n");
		
	}while(inicio != 's');

	do{	//Menu
			printf("MENU: \n");
			printf("\t1. Simular disparo\n\t2. Mostrar estat�sticas\n\t3. Sair\n");
			scanf("%d", &menu);
			
		switch(menu){
			case 1:
				printf("\nSIMULAR DISPARO\n\n");
				do{ //Velocidade
					printf("\tVelocidade inicial (V0): ");
					scanf("%f", &v0);
				}while(v0 < 0);
				do{ //�ngulo
					printf("\t�ngulo de inclina��o (entre 0 e 90): ");
					scanf("%f", &inclinacao);
				}while(inclinacao < 0 || inclinacao > 90);
				do{ //Dist�ncia
					printf("\tDist�ncia do alvo (em metros): ");
					scanf("%f", &distancia);
				}while(distancia < 0);
				do{ //Tamanho
					printf("\tTamanho do alvo (em metros): ");
					scanf("%f", &tamanho);
				}while(tamanho < 20 || tamanho > 50);
				
				angulo = inclinacao*(3.14/180);
				alturaMaxima = ((pow(v0, 2)) * sin(angulo))/(2*gravidade);
				tempoTrajeto = ((2*v0) * sin(angulo))/gravidade;
				alcanceHorizontal = 2*pow(v0, 2) * ((cos(angulo) * sin(angulo))/gravidade);
				
				printf("\nRESULTADOS:\n\n");
				printf("\tAltura M�xima: %.2fm\n\tTempo do Trajeto: %.2fs\n\tAlcance Horizontal: %.2fm\n\n", alturaMaxima, tempoTrajeto, alcanceHorizontal);
				
				if(alcanceHorizontal > distancia){
					if(alcanceHorizontal > distancia && alcanceHorizontal < distancia+tamanho){
						printf("Acertou o alvo!\n\n");
						acerto++;
					} else {
						printf("O proj�til caiu depois do alvo!\n\n");
					}
				} else {
					printf("O proj�til caiu antes do alvo!\n\n");
				}
				
				if(alturaMaxima > maiorAltura){
					maiorAltura = alturaMaxima;
				}
				
				media = media + alcanceHorizontal;
				divisaoMedia++;
				disparo++;
				menu = 0;
				break;
			case 2:
				porcentagem = (acerto * 100)/disparo;
				printf("\nMOSTRAR ESTAT�STICAS\n\n");
				printf("\tM�dia do alcance horizontal: %.2f\n", media/divisaoMedia);
				printf("\tMaior altura atingida dentre todos os disparos: %.2f\n", maiorAltura);
				printf("\tPorcentagem de disparos que atingiram o alvo: %.2f%%\n\n", porcentagem);
				menu = 0;
				break;
			case 3:
				printf("\nSAIR");
				return 0;
				break;
			default:
				printf("\nOP��O INV�LIDA\n\n");
				menu = 0;
				break;
		}
	}while(menu = 1 && 2 && 3);
}
