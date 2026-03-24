#include "arvoreb.h"

// Cria nó
No* criarNo(int folha){
    No* n = (No*)malloc(sizeof(No));
    n->n = 0;
    n->folha = folha;
    for(int i=0;i<ORDEM;i++)
        n->filhos[i] = NULL;
    return n;
}

// Divide filho cheio
void dividirFilho(No* x, int i){
    No* y = x->filhos[i];
    No* z = criarNo(y->folha);
    int t = (ORDEM-1)/2;

    z->n = y->n - t - 1;
    for(int j=0;j<z->n;j++)
        z->chaves[j] = y->chaves[j+t+1];

    if(!y->folha){
        for(int j=0;j<=z->n;j++)
            z->filhos[j] = y->filhos[j+t+1];
    }

    y->n = t;

    for(int j=x->n;j>=i+1;j--)
        x->filhos[j+1] = x->filhos[j];
    x->filhos[i+1] = z;

    for(int j=x->n-1;j>=i;j--)
        x->chaves[j+1] = x->chaves[j];

    x->chaves[i] = y->chaves[t];
    x->n++;
}

// Insere em nó não cheio
void inserirNaoCheio(No* x, int chave){
    int i = x->n-1;
    if(x->folha){
        while(i>=0 && x->chaves[i]>chave){
            x->chaves[i+1] = x->chaves[i];
            i--;
        }
        x->chaves[i+1] = chave;
        x->n++;
    } else {
        while(i>=0 && x->chaves[i]>chave) i--;
        i++;
        if(x->filhos[i]->n == ORDEM-1){
            dividirFilho(x,i);
            if(chave > x->chaves[i]) i++;
        }
        inserirNaoCheio(x->filhos[i], chave);
    }
}

// Insere na árvore
void inserir(No** raiz, int chave){
    if(*raiz == NULL){
        *raiz = criarNo(1);
        (*raiz)->chaves[0] = chave;
        (*raiz)->n = 1;
    } else {
        if((*raiz)->n == ORDEM-1){
            No* s = criarNo(0);
            s->filhos[0] = *raiz;
            dividirFilho(s,0);
            int i=0;
            if(s->chaves[0]<chave) i++;
            inserirNaoCheio(s->filhos[i], chave);
            *raiz = s;
        } else {
            inserirNaoCheio(*raiz,chave);
        }
    }
}

// Busca na árvore
No* buscar(No* x, int chave){
    int i=0;
    while(i<x->n && chave>x->chaves[i]) i++;
    if(i<x->n && chave==x->chaves[i]) return x;
    if(x->folha) return NULL;
    return buscar(x->filhos[i],chave);
}

// Imprime nó
void imprimirNo(No* x){
    if(!x) return;
    printf("[");
    for(int i=0;i<x->n;i++)
        printf("%d ", x->chaves[i]);
    printf("]");
    if(!x->folha){
        for(int i=0;i<=x->n;i++)
            imprimirNo(x->filhos[i]);
    }
}

// Libera memória da árvore
void liberarArvore(No* x){
    if(!x) return;
    if(!x->folha){
        for(int i=0;i<=x->n;i++)
            liberarArvore(x->filhos[i]);
    }
    free(x);
}
