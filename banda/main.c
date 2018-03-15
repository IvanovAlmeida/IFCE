/**
 * @file main.c
 * @author Ivanov de Almeida Moraes
 * @date 21-02-2018
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "variaveis.h"
#include "prototipos.h"
#include "funcoes.c"

int main() {
	int i, op, loop = 1;
	char str[80];
	struct banda *bandas;

	while(loop){
		
		mostrarOpcoes();
		scanf(" %d", &op);
		clear();
        resetarCorConsole();
		switch(op){

			case 1:
				//cadastrarBandas(bandas);
				cadastrarBanda(bandas);
				printf( ANSI_COLOR_GREEN "\n\nBandas cadastradas...\n");
				break;

			case 2:
				imprimirBandas(bandas);
				printf("\n");
				break;

			case 3:
				printf( ANSI_COLOR_CYAN "Escolha um indice para modificar: " ANSI_COLOR_YELLOW );
				scanf("%d", &i);
				i--;
				if(i >= 0 && i <= TAM)
					modificarBanda(&bandas[i]);
				else
					printf( ANSI_COLOR_RED "Indice inválido!\n");
				break;

			case 4:
				printf( ANSI_COLOR_CYAN "Informe um ranking para a busca: " ANSI_COLOR_YELLOW);
				scanf(" %d", &i);
                clear();
				i = buscarPorRanking(bandas, i);
				if(i >= 0)
					imprimirBanda(&bandas[i]);
				else
					printf( ANSI_COLOR_RED "Ranking não encontrado!\n");
				break;

			case 5:
				getchar();
				printf( ANSI_COLOR_CYAN "Informe um tipo para a busca: " ANSI_COLOR_YELLOW);
				gets(str);
                clear();
				buscarPorTipo(bandas, str);
				break;

			case 6:
				getchar();
				printf( ANSI_COLOR_CYAN "Informe o nome de uma banda: " ANSI_COLOR_YELLOW);
				gets(str);
				clear();
				if(inBandaArray(bandas, str))
					printf( ANSI_COLOR_GREEN "\nA banda " ANSI_COLOR_YELLOW "[ %s ]" ANSI_COLOR_GREEN " está no seu TOP 5!\n", str);
				else
					printf( ANSI_COLOR_RED "\nA banda " ANSI_COLOR_YELLOW "[ %s ]" ANSI_COLOR_RED " não está no seu TOP 5!\n", str);
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

    printf(ANSI_COLOR_MAGENTA "\nAplicação encerrada!\n\n" ANSI_COLOR_RESET);

	return 0;
}