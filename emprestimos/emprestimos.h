#ifndef LISTA_EMPRESTIMOS
#define LISTA_EMPRESTIMOS
#include "../usuarios/usuarios.h" // Seguro incluir

// Forward declaration para evitar ciclo com livros.h
struct NoLivro;

typedef struct NO_EMPRESTIMO{
    NoUsuario* usuario;
    char* dataEmprestimo;
    char* dataDevolucao;
    struct NO_EMPRESTIMO* proximo;
} NoEmprestimo; //implementação lista circular (o primeiro ponteiro nesse caso é o ultimo)

//Autor: Pedro
int emprestarLivro(NoLivro* livro, NoUsuario* usuario, char* dataEmprestimo, char* dataDevolucao);      //cria novo nó na lista de emprestimos de um livro
int devolverLivro(NoLivro* livro, NoUsuario* usuario);      //remove o nó de empréstimo
int freeListaEmprestimo(NoLivro* livro);        //remove a lista de empréstimos do livro
void exibirFilaEspera(NoLivro* livro);      //mostra a lista de espera de um livro
void listarEmprestimosPorUsuario(struct NO_LIVRO* header, NoUsuario* usuario);      //mostra todos os emprestimos de um usuário
#endif