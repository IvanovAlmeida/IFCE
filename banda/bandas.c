#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "estruturas.h"
#include "prototipos.h"

int main() {
	int i;
	char op;
	struct banda bandas[5];

	locale();

	while(1){
		
	setlocale(LC_ALL, "pt_BR_utf8");
		printf("á b é @ ç\n");
		//mostrarOpcoes();
		scanf(" %c", &op);
		system("cls|clear");

		switch(op){
			case 'a':
				cadastrarBandas(bandas);
				printf("\n\nBandas cadastradas...\n");
				break;
			case 'b':
				imprimirBandas(bandas);
				printf("\n\n");
				break;
			case 'c':
				printf("Escolha um indice para modificar\n");
				scanf("%d", &i);
				i--;
				if(i >= 0 && i <= 5){
					modificarBanda(&bandas[i]);
					printf("\nBanda modificada...\n");
				}
				else
					printf("Indice inválido!\n");
				break;
			default:
				printf("Opção inválida!\n");
				break;
		}	
		printf("Aperte qualquer tecla para voltar ao menu...\n");
		getchar();
		getchar();
	}

	return 0;
}

void mostrarOpcoes(){
	locale();
	system("cls|clear");
	printf("\n");
	printf("------- Menu -------\n");
	printf("a - Cadastar Bandas\n");
	printf("b - Imprimir Bandas\n");
	printf("C - Modificar Banda\n");
}

void cadastrarBanda(struct banda *b){
	locale();
	getchar();
	printf("Nome da banda: ");
	gets(b->nome);
	printf("Tipo: ");
	gets(b->tipo);
	printf("Número de integrantes: ");
	scanf("%d", &b->n_integrantes);
	printf("Ranking: ");
	scanf("%d", &b->pos_ranking);
}

void cadastrarBandas(struct banda b[5]){
	locale();
	for(int i=0; i < 5; i++){
		getchar();
		printf("%dª banda\n", i+1);
		printf("Nome da banda: ");
		gets(b[i].nome);
		printf("Tipo: ");
		gets(b[i].tipo);
		printf("Número de integrantes: ");
		scanf("%d", &b[i].n_integrantes);
		printf("Ranking: ");
		scanf("%d", &b[i].pos_ranking);
		system("cls|clear");
	}	
}

void imprimirBandas(struct banda b[5]){
	locale();
	for(int i=0; i < 5; i++){
		printf("\n");
		printf("Nome: %s\n", b[i].nome);
		printf("Tipo: %s\n", b[i].tipo);
		printf("Quantidade de integrantes: %d\n", b[i].n_integrantes);
		printf("Ranking: %d\n", b[i].pos_ranking);
	}
}

void modificarBanda(struct banda *b){
	locale();
	system("cls|clear");
	int op, loop = 1;

	while(1){
		printf("Modificando banda.\nSelecione o item que deseja alterar: \n");
		printf("[1] - Alterar nome da banda [ %s ]\n", b->nome);
		printf("[2] - Alterar tipo da banda [ %s ]\n", b->tipo);
		printf("[3] - Alterar número de integrantes [ %d ]\n", b->n_integrantes);
		printf("[4] - Alterar posição no ranking [ %d ]\n", b->pos_ranking);
		printf("\n");
		printf("[5] - Finalizar alterações\n");
		scanf(" %d", &op);

		switch(op){
			case 1:
				printf("Novo nome para a banda: ");
				gets(b->nome);
				break;
			case 2:
				printf("Novo tipo para a banda: ");
				gets(b->tipo);
				break;
			case 3:
				printf("Nova quantidade de integrantes: ");
				scanf("%d", &b->n_integrantes);
				break;
			case 4:
				printf("Nova posição no ranking: ");
				scanf("%d", &b->pos_ranking);
				break;
			case 5:
				loop = 0;
				break;
			default:
				printf("Opção inválida!\n");
				break;
		}
	}

	printf("Alterações finalizadas...\n");

}	

void locale(){

	printf("%s\n", setlocale(LC_ALL, "pt_BR_utf8"));
}