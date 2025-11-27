#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

//Definicao de struct
typedef struct{
    char nome[1];
    int id;
} Peca;

typedef struct {
    Peca itens[MAX];
    int inicio;
    int fim;
    int total;
} Fila;

//Funcoes
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

int filaCheia(Fila *f) {
    return f->total == MAX;
}
int filaVazia(Fila *f) {
    return f->total == 0;
}

void inserir(Fila *f, Peca p) {
    if (f->total == MAX) {
        printf("Fila cheia. Não é possível inserir.\n");
        return;
    }
 
    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX;
    f->total++;
}

void remover(Fila *f, Peca *p) {
    if (filaVazia(f)) {
        printf("Fila vazia. Não é possível remover.\n");
        return;
    }

    *p = f->itens[f->inicio];             
    f->inicio = (f->inicio + 1) % MAX;     
    f->total--;                        
}

void mostrarFila(Fila *f) {
    printf("Fila: ");
    for (int i = 0, idx = f->inicio; i < f->total; i++, idx = (idx + 1) % MAX) {
        printf("[%s, %d] ", f->itens[idx].nome, f->itens[idx].id);
    }
    printf("\n");
}

Peca gerarPeca(){
    int dado = (rand() % 4);
    Peca p;
    if(dado == 0){
        strcpy(p.nome, "I");
        p.id = 0;
    }
    else if(dado == 1){
        strcpy(p.nome, "O");
        p.id = 1;
    }
    else if(dado == 2){
        strcpy(p.nome, "T");
        p.id = 2;
    }
    else {
        strcpy(p.nome, "L");
        p.id = 3;
    }
    return p;
}

int main(){
    srand(time(NULL));

    Fila f;
    inicializarFila(&f);

    inserir(&f, gerarPeca());
    inserir(&f, gerarPeca());
    inserir(&f, gerarPeca());
    inserir(&f, gerarPeca());
    inserir(&f, gerarPeca());

    mostrarFila(&f);

    return 0;
}