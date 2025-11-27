#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

//Definicao de struct
typedef struct{
    char nome[30];
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
    int dado = (rand() % 3);
    if(dado = 0){
        Peca peca = {'I',0};
        return peca;
    }
    else if(dado = 1){
        Peca peca = {'O',1};
        return peca;
    }
    else if(dado = 2){
        Peca peca = {'T',2};
        return peca;
    }
    else if(dado = 3){
        Peca peca = {'L',3};
        return peca;
    }
}

int main(){
    Fila f;
    inicializarFila(&f);

    Peca p1 = {'I',0};
    Peca p2 = {'O',1};
    Peca p3 = {'T',2};
    Peca p4 = {'L',3};

    inserir(&f, p1);
    inserir(&f, p2);
    inserir(&f, p3);
    inserir(&f, p4);

    mostrarFila(&f);


    return 0;
}