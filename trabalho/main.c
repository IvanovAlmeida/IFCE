#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <malloc.h>

#ifndef  __WIN32__
    #include <curses.h>
#else
    #include <conio.h>
#endif


#define TAM 10
#define SNAKE_MAX 100
#define VIDA_DOCE 5
#define SIMBOL '#'


typedef struct posicao {
    int x, y;
} Posicao;

typedef struct snake {
    int tamanho;
    Posicao *pos;
} Snake;

typedef struct  doce {
    Posicao posicao;
    int vida;
} Doce;

Snake *snake;
Doce *doce;
char *tabuleiro;

void setPosicao(Posicao *posicao, int pos_X, int pos_Y){
    *(tabuleiro + pos_X + pos_Y) = SIMBOL;
    posicao->x = pos_X;
    posicao->y = pos_Y;
}

void inicializar(){

    tabuleiro = (char *) malloc(sizeof(char) * TAM * TAM);
    for(int i = 0; i < TAM * TAM; i++)
        *(tabuleiro + i) = '-';

    snake = (Snake *) malloc(sizeof(Snake));
    snake->tamanho = 3;
    snake->pos = (Posicao *) malloc(sizeof(Posicao) * snake->tamanho);

//    for(int i = 0; i < 3; i++)
//        *(tabuleiro + 0 + i) = '#';

    for(int i = 0; i < snake->tamanho; i++)
        setPosicao(snake->pos + i, 0, i);

//    snake = malloc(sizeof(Snake));
//    snake->tamanho = 3;
//    for(int i = 0; i < snake->tamanho; i++){
//        snake->pos[i] = malloc(sizeof(Posicao));
//        snake->pos[i]->x = 0;
//        snake->pos[i]->y = i;
//    }
}
void inicializarCobra(){

}

//void setSnake(){
//    for(int i = 0; i < snake->tamanho; i++){
//        tabuleiro[snake->pos[i]->x][snake->pos[i]->x] = '#';
//    }
//    tabuleiro[0][0] = '#';
//}

//void makeTabuleiro(){
//    for(int x = 0; x < TAM; x++){
//        for(int y = 0; y < TAM; y++){
//            tabuleiro[x][y] = "  ";
//        }
//    }
//    tabuleiro[0][0] = '#';
//    //setSnake();
//}

void gerarDoce(){
    srand((unsigned) time(NULL));
    doce->posicao.x = rand() % TAM;
    doce->posicao.y = rand() % TAM;
}

void ponteiroNulo(){}

void moveW(){
    printf("Cima");
}
void moveA(){
    printf("Esquerda");
}
void moveS(){
    printf("Baixo");
}
void moveD(){
    printf("Direita");
}


void movimentar(){
    char key;
//scanf("%c", &key);

    key = getch();

    switch (key){
        case 'W':
        case 'w':
            moveW();
            break;
        case 'A':
        case 'a':
            moveA();
            break;
        case 'S':
        case 's':
            moveS();
            break;
        case 'D':
        case 'd':
            moveD();
            break;
        case 'Q':
        case 'q':
            exit(0);
            break;
        default:
            printf("Teclas permitidas: para cima (tecla W), para baixo (tecla S), esquerda (tecla A) e direita (tecla D)");
            break;
    }
}



void imprimirTabuleiro(){

    printf("|");
    register int i;
    for(i = 0; i < TAM*TAM; i++) {
        printf("%c", *(tabuleiro + i));
        ((i+1) % TAM == 0) ? printf("|\n|") : 0;
    }

//    for(int x = 0; x < TAM; x++){
//        printf("|");
//        for(int y = 0; y < TAM; y++){
//            printf("%c", "*");
//        }
//        printf("|\n");
//    }

}

int main(){


    inicializar();
    imprimirTabuleiro();


    free(doce);
    free(snake->pos);
    free(snake);
    free(tabuleiro);

    return 0;
}