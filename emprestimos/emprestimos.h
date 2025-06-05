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

int emprestarLivro(NoLivro* livro, NoUsuario* usuario, char* dataEmprestimo, char* dataDevolucao);
int devolverLivro(NoLivro* livro, NoUsuario* usuario);
int freeListaEmprestimo(NoLivro* livro);
void exibirFilaEspera(NoLivro* livro);
void listarEmprestimosPorUsuario(struct NO_LIVRO* header, NoUsuario* usuario);
#endif