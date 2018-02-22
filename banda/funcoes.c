/**
 * @file funcoes.c
 * @author Ivanov de Almeida Moraes
 * @date 21-02-2018
 */

/**
 * @fn mostrarOpcoes()
 * @brief Mostra as opções do menu principal
 * @return void
 */
void mostrarOpcoes(){
	clear();
	printf("\n");
	printf(ANSI_COLOR_MAGENTA "---------- Menu ----------\n\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_MAGENTA " [ 1 ]" ANSI_COLOR_RESET ANSI_COLOR_CYAN " Cadastar Bandas\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_MAGENTA " [ 2 ]" ANSI_COLOR_RESET ANSI_COLOR_CYAN " Imprimir Bandas\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_MAGENTA " [ 3 ]" ANSI_COLOR_RESET ANSI_COLOR_CYAN " Modificar Banda\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_MAGENTA " [ 4 ]" ANSI_COLOR_RESET ANSI_COLOR_CYAN " Buscar por Ranking\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_MAGENTA " [ 5 ]" ANSI_COLOR_RESET ANSI_COLOR_CYAN " Buscar por Tipo\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_MAGENTA " [ 6 ]" ANSI_COLOR_RESET ANSI_COLOR_CYAN " Buscar no TOP 5\n" ANSI_COLOR_RESET);
	printf("\n");
	printf(ANSI_COLOR_MAGENTA " [ 0 ]" ANSI_COLOR_RESET ANSI_COLOR_CYAN " Sair\n" ANSI_COLOR_RESET);
	//printf(ANSI_COLOR_MAGENTA "\n--------------------------" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_MAGENTA "\n=> " ANSI_COLOR_RESET);
}

/**
 * @fn cadastrarBanda(struct banda *b)
 * @brief Cadastra uma banda
 * @param strunct banda *b
 * @return void
 */
void cadastrarBanda(struct banda *b){
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

/**
 * @fn cadastrarBandas(struct banda b[])
 * @brief Cadastra varias bandas
 * @param struct bandas b[]
 * @return void
 */
void cadastrarBandas(struct banda b[TAM]){
	for(int i=0; i < TAM; i++){
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
		clear();
	}	
}

/**
 * @fn imprimirBanda(struct banda *b)
 * @brief imprime uma única banda
 * @param struct banda *b
 * @return void
 */
void imprimirBanda(struct banda *b){
	printf("---------------------------------------------------\n\n");
	printf("Nome: %s\n", b->nome);
	printf("Tipo: %s\n", b->tipo);
	printf("Quantidade de integrantes: %d\n", b->n_integrantes);
	printf("Ranking: %d\n", b->pos_ranking);
	printf("\n---------------------------------------------------\n");
}

/**
 * @fn imprimirBandas(struct banda b[])
 * @brief imprime varias bandas
 * @param struct banda b[]
 * @return void
 */
void imprimirBandas(struct banda b[TAM]){
	printf("---------------------------------------------------\n");
	for(int i=0; i < TAM; i++){
		printf("\n");
		printf("ID: %d\n", i+1);
		printf("Nome: %s\n", b[i].nome);
		printf("Tipo: %s\n", b[i].tipo);
		printf("Quantidade de integrantes: %d\n", b[i].n_integrantes);
		printf("Ranking: %d\n", b[i].pos_ranking);
		printf("\n---------------------------------------------------\n");
	}
}

/**
 * @fn modificarBanda(struct banda *b)
 * @brief Modifica uma unica banda, podendo selecionar o campo a ser alterado.
 * @param struct banda *b
 * @return void
 */
void modificarBanda(struct banda *b){
	clear();
	int op, loop = 1;

	while(loop){
		clear();
		printf("Selecione o item que deseja alterar: \n");
		printf(" [ 1 ] - Alterar nome da banda [ %s ]\n", b->nome);
		printf(" [ 2 ] - Alterar tipo da banda [ %s ]\n", b->tipo);
		printf(" [ 3 ] - Alterar número de integrantes [ %d ]\n", b->n_integrantes);
		printf(" [ 4 ] - Alterar posição no ranking [ %d ]\n", b->pos_ranking);
		printf(" [ 5 ] - Alterar todos os campos\n");
		printf("\n");
		printf(" [ 0 ] - Finalizar alterações\n");
		printf("\n=> ");
		scanf(" %d", &op);
		getchar();
		clear();
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
				printf("Novo nome para a banda: ");
				gets(b->nome);
				printf("Novo tipo para a banda: ");
				gets(b->tipo);
				printf("Nova quantidade de integrantes: ");
				scanf("%d", &b->n_integrantes);
				printf("Nova posição no ranking: ");
				scanf("%d", &b->pos_ranking);
				break;
			case 0:
				loop = 0;
				break;
			default:
				printf(ANSI_COLOR_RED "Opção inválida!\n" ANSI_COLOR_RESET);
				break;
		}
	}

	printf(ANSI_COLOR_GREEN   "Alterações finalizadas...\n\n" ANSI_COLOR_RESET );

}	

/**
 * @fn buscarPorRanking(struct banda b[], int ranking)
 * @brief Busca uma banda dentro do array, retorna o indice dentro do array caso exista ou -1 se não existir
 * @param struct banda b[]
 * @param int ranking
 * @return int posicao
 */
int buscarPorRanking(struct banda b[TAM], int ranking){
	int i;
	for(i = 0; i < TAM; i++){
		if(b[i].pos_ranking == ranking)
			return i;	
	}
	
	return -1;
}

/**
 * @fn buscarPorTipo(struct banda b[TAM], char tipo[80])
 * @brief Busca uma banda por tipo e imprime
 * @param struct banda b[]
 * @param char tipo[]
 * @return void
 */
void buscarPorTipo(struct banda b[TAM], char tipo[80]){
	int i, cont = 0;
	for(i = 0; i < TAM; i++){
		if(strcmp(b[i].tipo, tipo)  == 0 ){
            imprimirBanda(&b[i]);
            cont++;
        }
	}
    if(cont)
        printf("\nNenhuma banda encontada com o tipo informado!\n");
}

/**
 * @fn inBandaArray(struct banda b[TAM], char nome[80])
 * @brief Verifica uma banda passada pelo usuário está no array.
 * @param struct banda b[TAM]
 * @param char nome[80]
 * @returns int 0|1
 */
int inBandaArray(struct banda b[TAM], char nome[80]){
    for(int i = 0; i < TAM; i++)
        if(strcmp(b[i].nome, nome) == 0)
            return 1;
    return 0;
}

/**
 * @fn clear()
 * @brief Limpa a tela
 * @return void
 */
void clear(){
	system("@cls||clear");
}

/**
 * @fn pause()
 * @brief Pausa o programa até que o usuário tecle algo.
 * @return void
 */
void pause(){
	printf("Aperte qualquer tecla para voltar ao menu...\n");
	getchar();
	getchar();
}