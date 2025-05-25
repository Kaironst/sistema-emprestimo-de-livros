#include "emprestimos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int emprestarLivro(NoLivro* livro, NoUsuario* usuario, char* dataEmprestimo, char* dataDevolucao) {
    NoEmprestimo* novo = (NoEmprestimo*)malloc(sizeof(NoEmprestimo));
    novo->usuario=usuario;
    novo->dataEmprestimo=dataEmprestimo;
    novo->dataDevolucao=dataDevolucao;
    if (livro->emprestimos==NULL) {     //inicializa a lista caso não hajam emprestimos do livro
        livro->emprestimos = novo;
        novo->proximo=novo;
    }
    else {
        novo->proximo=livro->emprestimos->proximo;      //adiciona no final
        livro->emprestimos->proximo=novo;
        livro->emprestimos=novo;
    }
    usuario->numEmprestimos++;
    livro->qtdeDisponivel--;
    return 1;
}

int devolverLivro(NoLivro* livro, NoUsuario* usuario) {
    NoEmprestimo* atual = livro->emprestimos;
    NoEmprestimo* anterior = livro->emprestimos;
    do {
        if (strcmp(atual->usuario,usuario)==0) break;
        anterior=atual;
        atual=atual->proximo;
    }while(atual!=livro->emprestimos);
    if (strcmp(atual->usuario,usuario)!=0) return 0;
    anterior->proximo=atual->proximo;
    free(atual); //checar esse código
    livro->qtdeDisponivel++;
    usuario->numEmprestimos--;
    return 1;
}

int freeListaEmprestimo(NoLivro* livro) {
    while (livro->emprestimos != NULL) {
        NoEmprestimo* aux = livro->emprestimos->proximo;
        livro->emprestimos->proximo=livro->emprestimos->proximo->proximo;
        aux->usuario->numEmprestimos--;
        free(aux);
        aux=NULL;
        livro->qtdeDisponivel++;
    }
    return 1;
}