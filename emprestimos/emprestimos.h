#ifndef LISTA_EMPRESTIMOS
#define LISTA_EMPRESTIMOS
#include "../usuarios/usuarios.h"
#include "../livros/livros.h"

typedef struct NO_EMPRESTIMO{
    NoUsuario* usuario;
    char* dataEmprestimo;
    char* dataDevolucao;
    struct NO_EMPRESTIMO* proximo;
} NoEmprestimo; //implementação lista circular (o primeiro ponteiro nesse caso é o ultimo)

int emprestarLivro(NoLivro* livro, NoUsuario* usuario, char* dataEmprestimo, char* dataDevolucao);
int devolverLivro(NoLivro* livro, NoUsuario* usuario);
int freeListaEmprestimo(NoLivro* livro);
#endif