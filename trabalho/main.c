#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//#define __WIN32__ 0

#ifndef  __WIN32__
  #include <ncurses.h>
    puts("ncurses");
#elseif
    #include <conio.h>
    puts ("conio");
#endif


#define TAM 10
#define SNAKE_MAX 100
#define VIDA_DOCE 5
#define DOCE "#"


typedef struct posicao {
    int x, y;
} Posicao;

typedef struct snake {
    int tamanho;
    Posicao *pos[];
} Snake;

typedef struct  doce {
    Posicao posicao;
    int vida;
} Doce;

Snake *snake;
Doce *doce;
char tabuleiro[TAM][TAM];

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

inicializarCobra(){

}

void imprimirTabuleiro(){

    for(int i = 0; i < TAM; i++){
        printf("|");
        for(int j = 0; j < TAM; j++){

            printf("   ");
        }
        printf("|\n");
    }

}

int main(){

    imprimirTabuleiro();

    return 0;
}