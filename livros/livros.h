#ifndef LISTA_LIVROS
#define LISTA_LIVROS
#include "../emprestimos/emprestimos.h"

typedef struct NO_LIVRO {
    char *titulo;
    char *autor;
    int cod;
    int qtdeDisponivel;
    NoEmprestimo* emprestimos;
    NoFila* filaEspera;
    struct NO_LIVRO *proximo;
    struct NO_LIVRO *anterior;
}NoLivro;  //implementação da lista dupla com cabeçalho

NoLivro* iniListaLivro();        //cria lista
int addLivro(NoLivro* header,char* titulo, char* autor, int cod, int qtdeDisponivel);       //adiciona livro no inicio da lista
int rmLivro(NoLivro* No);      //remove livro especificado pelo nó
NoLivro* getLivro(NoLivro* header, char* titulo);       //retorna um livro pelo título
NoLivro* getLivroCod(NoLivro* header, int cod);     //retorna um livro pelo cod
int setQtde(NoLivro* no, int qtde);
int freeListaLivro(NoLivro* header);        //libera a lista


#endif