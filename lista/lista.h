#ifndef LISTA_FILA
#define LISTA_FILA
#include "../usuarios/usuarios.h" // Seguro incluir

// Forward declaration para evitar ciclo com livros.h
struct NoLivro;

typedef struct NO_FILA {
NoUsuario* usuario;
char* dataRequisicao;
struct NO_FILA* proximo;
}NoFila;        // lista circular (primeiro é o último)

int addFilaLivro(NoLivro* livro, NoUsuario* usuario, char* dataEmprestimo, char* dataDevolucao);    //adiciona um usuario na fila de espera do livro
int rmFilaLivro(NoLivro* livro, NoUsuario* usuario);        //remove um usuário da fila de espera do livro
int freeListaFila(NoLivro* livro);      //libera o espaço tomado pela lista de espera

#endif