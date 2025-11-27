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
    //Verifica se aa fila esta cheia
    if (f->total == MAX) {
        printf("Fila cheia. Não é possível inserir.\n");
        return;
    }
 
    //Insere peca
    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX;
    f->total++;
}

Peca remover(Fila *f) {
    Peca removida;

    if (filaVazia(f)) {
        printf("Fila vazia. Não é possível remover.\n");
        strcpy(removida.nome, "VAZIO");
        removida.id = -1;
        return removida;
    }

    removida = f->itens[f->inicio];         // pega o item
    f->inicio = (f->inicio + 1) % MAX;      // avança o início
    f->total--;                             // diminui quantidade

    return removida;                      
}

void mostrarFila(Fila *f) {
    //Percorre a fila e mostra no terminal
    printf("Fila: ");
    for (int i = 0, idx = f->inicio; i < f->total; i++, idx = (idx + 1) % MAX) {
        printf("[%s, %d] ", f->itens[idx].nome, f->itens[idx].id);
    }
    printf("\n");
}

Peca gerarPeca(){
    //Gera uma peca aleatoria
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

    //Iniciaaliza a fila
    Fila f;
    inicializarFila(&f);

    //Isere algumas pecas
    inserir(&f, gerarPeca());
    inserir(&f, gerarPeca());
    inserir(&f, gerarPeca());
    inserir(&f, gerarPeca());
    inserir(&f, gerarPeca());

    //Mostra a fila
    mostrarFila(&f);

    //Removver peca
    /*
    Peca r = remover(&f);
    printf("Removido: [%s id=%d]\n", r.nome, r.id);
    mostrarFila(&f);
    */
    return 0;
}