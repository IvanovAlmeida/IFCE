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
 * @fn cadastrarBanda(Banda *b)
 * @brief Cadastra uma banda
 * @param strunct banda *b
 * @return void
 */
void cadastrarBanda(Banda *b);
/**
 * @fn cadastrarBandas(Banda b[])
 * @brief Cadastra varias bandas
 * @param struct bandas b[]
 * @return void
 */
void cadastrarBandas(Banda b[TAM]);

/**
 * @fn imprimirBanda(Banda *b)
 * @brief imprime uma única banda
 * @param struct banda *b
 * @return void
 */
void imprimirBanda(Banda *b);
/**
 * @fn imprimirBandas(Banda b[])
 * @brief imprime varias bandas
 * @param struct banda b[]
 * @return void
 */
void imprimirBandas(Banda b[TAM]);

/**
 * @fn modificarBanda(Banda *b)
 * @brief Modifica uma unica banda, podendo selecionar o campo a ser alterado.
 * @param struct banda *b
 * @return void
 */
void modificarBanda(int pos);

/**
 * @fn buscarPorRanking(Banda b[], int ranking)
 * @brief Busca uma banda dentro do array, retorna o indice dentro do array caso exista ou -1 se não existir
 * @param struct banda b[]
 * @param int ranking
 * @return int posicao
 */
int buscarPorRanking(Banda b[TAM], int ranking);

/**
 * @fn buscarPorTipo(Banda b[TAM], char tipo[80])
 * @brief Busca uma banda por tipo e imprime
 * @param struct banda b[]
 * @param char tipo[]
 * @return void
 */
void buscarPorTipo(Banda b[TAM], char tipo[80]);

/**
 * @fn inBandaArray(Banda b[TAM], char nome[80])
 * @brief Verifica uma banda passada pelo usuário está no array.
 * @param struct banda b[TAM]
 * @param char nome[80]
 * @returns int 0|1
 */
int inBandaArray(Banda b[TAM], char nome[80]);

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