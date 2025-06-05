#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../usuarios/usuarios.h"
#include "../livros/livros.h"
#include "lista.h"

// Inicializa a lista de fila (retorna NULL para fila vazia)
NoEmprestimo* iniListaFila() {
    return NULL; // Uma fila vazia é simplesmente representada por um ponteiro NULL
                 // Não há necessidade de alocar memória inicialmente para representar a fila
}

// Função auxiliar para criar um novo nó
static NoFila* criarNoFila(NoUsuario* usuario, const char* dataRequisicao) {
    NoFila* novo = (NoFila*) malloc(sizeof(NoFila));
    novo->usuario = usuario;
    novo->dataRequisicao = strdup(dataRequisicao);
    if (!novo->dataRequisicao) {
        free(novo);
        return NULL;
    }

    novo->proximo = NULL;
    return novo;
}

// Adiciona um usuário na fila circular do livro
int addFilaLivro(NoLivro* livro, NoUsuario* usuario, char* dataEmprestimo, char* dataDevolucao) {
    NoFila* novo = criarNoFila(usuario, dataEmprestimo);

    if (!livro->filaEspera) {
        // Fila vazia: nó aponta para ele mesmo
        novo->proximo = novo;
        livro->filaEspera = novo;
    } else {
        // Insere novo nó no final da fila
        NoFila* ultimo = livro->filaEspera;
        while (ultimo->proximo != livro->filaEspera) {
            ultimo = ultimo->proximo;
        }
        ultimo->proximo = novo;
        novo->proximo = livro->filaEspera;
    }
    return 1;
}

// Remove um usuário da fila circular do livro
int rmFilaLivro(NoLivro* livro, NoUsuario* usuario) {
    if (!livro || !livro->filaEspera || !usuario) return 0;

    NoFila* atual = livro->filaEspera;
    NoFila* anterior = NULL;

    do {
        if (atual->usuario == usuario) {
            if (anterior) {
                anterior->proximo = atual->proximo;
            }

            // Se for único elemento da fila
            if (atual->proximo == atual) {
                livro->filaEspera = NULL;
            } else {
                if (atual == livro->filaEspera) {
                    livro->filaEspera = atual->proximo;
                }
                if (!anterior) {
                    // Remover o primeiro, ajustar último
                    NoFila* ultimo = livro->filaEspera;
                    while (ultimo->proximo != atual) {
                        ultimo = ultimo->proximo;
                    }
                    ultimo->proximo = atual->proximo;
                }
            }

            free(atual->dataRequisicao);
            free(atual);
            return 1;
        }
        anterior = atual;
        atual = atual->proximo;
    } while (atual != livro->filaEspera);

    return 0; // Usuário não encontrado na fila
}

// Libera toda a fila circular de um livro
int freeListaFila(NoLivro* livro) {
    if (!livro || !livro->filaEspera) return 0;

    NoFila* atual = livro->filaEspera->proximo;
    NoFila* temp;

    while (atual != livro->filaEspera) {
        temp = atual->proximo;
        free(atual->dataRequisicao);
        free(atual);
        atual = temp;
    }

    // Libera o último nó (início)
    free(livro->filaEspera->dataRequisicao);
    free(livro->filaEspera);
    livro->filaEspera = NULL;

    return 1;
}