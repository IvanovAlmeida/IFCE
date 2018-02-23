/**
 * @file variaveis.h
 * @author Ivanov de Almeida Moraes
 * @date 21-02-2018
 */

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define TAM 3

struct banda {
	char nome[80];
	char tipo[80];
	int n_integrantes;
	int pos_ranking;
};