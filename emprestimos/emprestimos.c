#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../usuarios/usuarios.h"
#include "../livros/livros.h"
#include "../lista/lista.h"
#include "emprestimos.h"

int emprestarLivro(NoLivro* livro, NoUsuario* usuario, char* dataEmprestimo, char* dataDevolucao) {
    //caso não esteja disponível, adicionar à fila de espera
    if (livro->qtdeDisponivel <= 0) {
        // Livro indisponível → Adiciona à fila
        printf("Livro indisponível. Usuário adicionado à fila de espera.\n");
        addFilaLivro(livro, usuario, dataEmprestimo, dataDevolucao);
        return 0;
    }

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
    free(atual);
    usuario->numEmprestimos--;
    livro->qtdeDisponivel++;

    // Se há fila de espera, empresta ao próximo usuário
    if (livro->filaEspera != NULL) {
        NoUsuario* proximoUsuario = livro->filaEspera->usuario;
        char* dataReq = strdup(livro->filaEspera->dataRequisicao);
        rmFilaLivro(livro, proximoUsuario);
        emprestarLivro(livro, proximoUsuario, dataReq, "DATA_DEV_PADRAO");
        free(dataReq);
    }

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

void exibirFilaEspera(NoLivro* livro) {
    if (!livro || !livro->filaEspera) {
        printf("Sem fila de espera para o livro mencionado.\n");
        return;
    }

    NoFila* atual = livro->filaEspera;
    printf("Fila de espera para o livro '%s':\n", livro->titulo);
    do {
        printf("- %s | Data de solicitação: %s\n", atual->usuario->nome, atual->dataRequisicao);
        atual = atual->proximo;
    } while (atual != livro->filaEspera);
}

void listarEmprestimosPorUsuario(NoLivro* header, NoUsuario* usuario) {
    NoLivro* livro = header->proximo;
    int encontrou = 0;

    while (livro != NULL) {
        NoEmprestimo* emp = livro->emprestimos;
        if (emp != NULL) {
            NoEmprestimo* atual = emp;
            do {
                if (atual->usuario == usuario) {
                    printf("Livro: %s | Empréstimo: %s | Devolução: %s\n",
                           livro->titulo, atual->dataEmprestimo, atual->dataDevolucao);
                    encontrou = 1;
                }
                atual = atual->proximo;
            } while (atual != emp);
        }
        livro = livro->proximo;
    }

    if (!encontrou) {
        printf("Nenhum empréstimo encontrado para o usuário %s.\n", usuario->nome);
    }
}