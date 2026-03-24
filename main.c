#include <stdio.h>
#include <stdlib.h>
#include "arvoreb.h"

int main(){
    FILE* arq = fopen("registros.txt","a+");
    if(!arq){ printf("Erro abrir arquivo\n"); return 1; }

    Registro r;
    No* raiz = NULL;
    int op;

    // Inicializa árvore com registros existentes
    rewind(arq);
    long pos;
    while(fscanf(arq,"%d %s %s",&r.matricula,r.nome,r.telefone)==3){
        inserir(&raiz,r.matricula);
    }

    do{
        printf("\n1-Cadastrar\n2-Pesquisar\n3-Ver Arquivo\n4-Sair\n");
        scanf("%d",&op);

        if(op==1){
            printf("Matricula: "); scanf("%d",&r.matricula);
            printf("Nome: "); scanf(" %[^\n]", r.nome);
            printf("Telefone: "); scanf(" %[^\n]", r.telefone);

            fprintf(arq,"%d %s %s\n", r.matricula, r.nome, r.telefone);
            fflush(arq);

            inserir(&raiz,r.matricula);
            printf("Registro cadastrado e inserido na árvore B\n");
        }
        else if(op==2){
            int mat; printf("Matricula: "); scanf("%d",&mat);
            No* achou = buscar(raiz, mat);
            if(achou){
                rewind(arq);
                while(fscanf(arq,"%d %s %s",&r.matricula,r.nome,r.telefone)==3){
                    if(r.matricula==mat){
                        printf("Nome: %s\nTelefone: %s\n", r.nome,r.telefone);
                        break;
                    }
                }
            } else printf("Nao encontrado\n");
        }
        else if(op==3){
            rewind(arq);
            printf("\n--- CONTEUDO DE registros.txt ---\n");
            while(fscanf(arq,"%d %s %s",&r.matricula,r.nome,r.telefone)==3)
                printf("%d %s %s\n", r.matricula,r.nome,r.telefone);
        }

    }while(op!=4);

    liberarArvore(raiz);
    fclose(arq);
    printf("Memória liberada. Programa encerrado.\n");

    return 0;
}
