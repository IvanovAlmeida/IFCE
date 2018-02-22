/**
 * @file main.c
 * @author Ivanov de Almeida Moraes
 * @date 21-02-2018
 */

#include <stdio.h>
#include <string.h>
#include "variaveis.h"
#include "prototipos.h"
#include "funcoes.c"

int main() {
	int i, op, loop = 1;
	char str[80];
	struct banda bandas[TAM];

	while(loop){
		
		mostrarOpcoes();
		scanf(" %d", &op);
		clear();

		switch(op){

			case 1:
				cadastrarBandas(bandas);
				printf("\n\nBandas cadastradas...\n");
				break;

			case 2:
				imprimirBandas(bandas);
				printf("\n\n");
				break;

			case 3:
				printf("Escolha um indice para modificar\n");
				scanf("%d", &i);
				i--;
				if(i >= 0 && i <= TAM)
					modificarBanda(&bandas[i]);
				else
					printf("Indice inválido!\n");
				break;

			case 4:
				printf("Informe um ranking para a busca: ");
				scanf(" %d", &i);
				i = buscarPorRanking(bandas, i);
				if(i >= 0)
					imprimirBanda(&bandas[i]);
				else
					printf("Ranking não encontrado!\n");
				break;

			case 5:
				getchar();
				printf("Informe um tipo para a busca: ");
				gets(str);
				buscarPorTipo(bandas, str);
				break;

			case 6:
				getchar();
				printf("Informe o nome de uma banda: ");
				gets(str);
				clear();
				if(inBandaArray(bandas, str))
					printf("\nA banda [ %s ] está no seu TOP 5!\n", str);
				else
					printf("A banda [ %s ] não está no seu TOP 5!\n", str);
				break;

            case 0:
                loop = 0;
                break;

			default:
				printf(ANSI_COLOR_RED "Opção inválida!\n\n" ANSI_COLOR_RESET);
				break;

		}
        if(op != 0)
		    pause();
	}

    printf(ANSI_COLOR_RED "\nAplicação encerrada!\n\n" ANSI_COLOR_RESET );

	return 0;
}