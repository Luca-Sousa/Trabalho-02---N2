/* Escreva uma função que, dado duas filas F1 e F2, concatene as duas filas.
Retorne a fila concatenada em F1. A fila F2 ao Final deve ficar vazia.

Equipe 1: 
1. LUCAS DE SOUSA SILVA 
2. FRANCISCO ALISSON COSTA ARAÚJO
3. VANDI VIEIRA DOS SANTOS JÚNIOR 
*/

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do No
typedef struct Node {
    int valor;
    struct Node* prox;
} No;

// Definição da estrutura dos Elementos da Fila
typedef struct {
    No* inicio;
    No* fim;
} Fila;

//Função para Inicialização da Fila
void inicializarFila(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

//Função para Verificar se a Fila está Vazia
int filaVazia(Fila* fila) {
    return (fila->inicio == NULL);
}

//Função para Enfileirar os Elmentos da Fila
void enfileirar(Fila* fila, int valor)  {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->prox = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } 
    else {
        fila->fim->prox = novoNo;
        fila->fim = novoNo;
    }
}

//Função para Desenfileirar os Elmentos da Fila
int desenfileirar(Fila* fila)  {

    if (filaVazia(fila)) {
        printf("Erro: A fila está vazia.\n");
        return -1; // Valor inválido para indicar erro
    }

    No* noRemovido = fila->inicio;
    int valor = noRemovido->valor;
    fila->inicio = fila->inicio->prox;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(noRemovido);

    return valor;
}

//Função para Contanear os elementos das Filas
void concatenarFilas(Fila* F1, Fila* F2)  {

    while (!filaVazia(F2))  {
        int valor = desenfileirar(F2);
        enfileirar(F1, valor);
    }
}

//Função para Imprimir os elementos das Filas
void imprimirFila(Fila* fila)  {

    No* atual = fila->inicio;

    while (atual != NULL)  {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

//Função Principal
int main()  {

    Fila F1, F2;
    inicializarFila(&F1);
    inicializarFila(&F2);

    int n, i, valor;

    printf("Quantos elementos deseja inserir na fila F1? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Informe o elemento %d da F1: ", i + 1);
        scanf("%d", &valor);
        enfileirar(&F1, valor);
    }

    printf("--------------------------------------------\n");

    printf("Quantos elementos deseja inserir na fila F2? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Informe o elemento %d da F2: ", i + 1);
        scanf("%d", &valor);
        enfileirar(&F2, valor);
    }

    printf("------------------------------\n");

    printf("Fila F1 antes da concatenacao: ");
    imprimirFila(&F1);

    printf("Fila F2 antes da concatenacao: ");
    imprimirFila(&F2);

    concatenarFilas(&F1, &F2);

    printf("----------------------------\n");

    printf("Fila F1 apos a concatenacao: ");
    imprimirFila(&F1);

    printf("Fila F2 apos a concatenacao: ");
    imprimirFila(&F2);

    return 0;
}