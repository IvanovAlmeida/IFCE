/**
 * @file prototipos.h
 * @author Ivanov de Almeida Moraes
 * @date 21-02-2018
 */

/**
 * @fn mostrarOpcoes()
 * @brief Mostra as opções do menu principal
 * @return void
 */
void mostrarOpcoes();

/**
 * @fn cadastrarBanda(struct banda *b)
 * @brief Cadastra uma banda
 * @param strunct banda *b
 * @return void
 */
void cadastrarBanda(struct banda *b);
/**
 * @fn cadastrarBandas(struct banda b[])
 * @brief Cadastra varias bandas
 * @param struct bandas b[]
 * @return void
 */
void cadastrarBandas(struct banda b[TAM]);

/**
 * @fn imprimirBanda(struct banda *b)
 * @brief imprime uma única banda
 * @param struct banda *b
 * @return void
 */
void imprimirBanda(struct banda *b);
/**
 * @fn imprimirBandas(struct banda b[])
 * @brief imprime varias bandas
 * @param struct banda b[]
 * @return void
 */
void imprimirBandas(struct banda b[TAM]);

/**
 * @fn modificarBanda(struct banda *b)
 * @brief Modifica uma unica banda, podendo selecionar o campo a ser alterado.
 * @param struct banda *b
 * @return void
 */
void modificarBanda(struct banda *b);

/**
 * @fn buscarPorRanking(struct banda b[], int ranking)
 * @brief Busca uma banda dentro do array, retorna o indice dentro do array caso exista ou -1 se não existir
 * @param struct banda b[]
 * @param int ranking
 * @return int posicao
 */
int buscarPorRanking(struct banda b[TAM], int ranking);

/**
 * @fn buscarPorTipo(struct banda b[TAM], char tipo[80])
 * @brief Busca uma banda por tipo e imprime
 * @param struct banda b[]
 * @param char tipo[]
 * @return void
 */
void buscarPorTipo(struct banda b[TAM], char tipo[80]);

/**
 * @fn inBandaArray(struct banda b[TAM], char nome[80])
 * @brief Verifica uma banda passada pelo usuário está no array.
 * @param struct banda b[TAM]
 * @param char nome[80]
 * @returns int 0|1
 */
int inBandaArray(struct banda b[TAM], char nome[80]);

/**
 * @fn clear()
 * @brief Limpa a tela
 * @return void
 */
void clear();

/**
 * @fn pause()
 * @brief Pausa o programa até que o usuário tecle algo.
 * @return void
 */
void pause();