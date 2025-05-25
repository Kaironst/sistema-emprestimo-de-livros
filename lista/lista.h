#ifndef LISTA_FILA
#define LISTA_FILA
#include "../usuarios/usuarios.h"
#include "../livros/livros.h"

typedef struct NO_FILA {
NoUsuario* usuario;
char* dataRequisicao;
struct NO_FILA* proximo;
}NoFila;        // lista circular (primeiro é o último)

NoEmprestimo* iniListaFila();
int addFilaLivro(NoLivro* livro, NoUsuario* usuario, char* dataEmprestimo, char* dataDevolucao);
int rmFilaLivro(NoLivro* livro, NoUsuario* usuario);
int freeListaFila(NoLivro* livro);

#endif