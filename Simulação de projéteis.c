#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int menu;
	char inicio = 's';
	float v0, inclinacao, distancia, tamanho, gravidade = 9.81;  //Informações para cálculos
	float alturaMaxima = 0, tempoTrajeto = 0, alcanceHorizontal = 0, angulo = 0; //Variáveis de cálculo
	float maiorAltura = 0, media = 0, divisaoMedia = 0, porcentagem = 0, disparo = 0, acerto=0;; //Estatisticas
	
	do{ //Apresentação
		printf("Simulador de lançamento de projéteis\n\n\tby Lucas Mello dos Santos\n\n");
		printf("Executar programa? (s/n)\n");
		scanf(" %c", &inicio);
		printf("\n");
		
	}while(inicio != 's');

	do{	//Menu
			printf("MENU: \n");
			printf("\t1. Simular disparo\n\t2. Mostrar estatísticas\n\t3. Sair\n");
			scanf("%d", &menu);
			
		switch(menu){
			case 1:
				printf("\nSIMULAR DISPARO\n\n");
				do{ //Velocidade
					printf("\tVelocidade inicial (V0): ");
					scanf("%f", &v0);
				}while(v0 < 0);
				do{ //Ângulo
					printf("\tÂngulo de inclinação (entre 0 e 90): ");
					scanf("%f", &inclinacao);
				}while(inclinacao < 0 || inclinacao > 90);
				do{ //Distância
					printf("\tDistância do alvo (em metros): ");
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
				printf("\tAltura Máxima: %.2fm\n\tTempo do Trajeto: %.2fs\n\tAlcance Horizontal: %.2fm\n\n", alturaMaxima, tempoTrajeto, alcanceHorizontal);
				
				if(alcanceHorizontal > distancia){
					if(alcanceHorizontal > distancia && alcanceHorizontal < distancia+tamanho){
						printf("Acertou o alvo!\n\n");
						acerto++;
					} else {
						printf("O projétil caiu depois do alvo!\n\n");
					}
				} else {
					printf("O projétil caiu antes do alvo!\n\n");
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
				printf("\nMOSTRAR ESTATÍSTICAS\n\n");
				printf("\tMédia do alcance horizontal: %.2f\n", media/divisaoMedia);
				printf("\tMaior altura atingida dentre todos os disparos: %.2f\n", maiorAltura);
				printf("\tPorcentagem de disparos que atingiram o alvo: %.2f%%\n\n", porcentagem);
				menu = 0;
				break;
			case 3:
				printf("\nSAIR");
				return 0;
				break;
			default:
				printf("\nOPÇÃO INVÁLIDA\n\n");
				menu = 0;
				break;
		}
	}while(menu = 1 && 2 && 3);
}
