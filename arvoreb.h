#ifndef ARVOREB_H
#define ARVOREB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ORDEM 3  // ordem mínima (2 <= ORDEM)

typedef struct {
    int matricula;
    char nome[100];
    char telefone[20];
} Registro;

typedef struct No {
    int n;                    // número de chaves
    int chaves[ORDEM-1];      // vetor de chaves
    struct No* filhos[ORDEM]; // ponteiros para filhos
    int folha;                // 1 se folha
} No;

// Funções da árvore B
No* criarNo(int folha);
void dividirFilho(No* x, int i);
void inserirNaoCheio(No* x, int chave);
void inserir(No** raiz, int chave);
No* buscar(No* x, int chave);
void imprimirNo(No* x);
void liberarArvore(No* x);

#endif
