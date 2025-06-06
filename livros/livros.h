#ifndef LISTA_LIVROS
#define LISTA_LIVROS

// Forward declarations para evitar ciclos
struct NO_EMPRESTIMO;
struct NO_FILA;

typedef struct NO_LIVRO {
    char *titulo;
    char *autor;
    int cod;
    int qtdeDisponivel;
    struct NO_EMPRESTIMO* emprestimos;
    struct NO_FILA* filaEspera;
    struct NO_LIVRO *proximo;
    struct NO_LIVRO *anterior;
}NoLivro;  //implementação da lista dupla com cabeçalho

//Autor: Bruno
NoLivro* iniListaLivro();        //cria lista
int addLivro(NoLivro* header,char* titulo, char* autor, int cod, int qtdeDisponivel);       //adiciona livro no inicio da lista
int rmLivro(NoLivro* No);      //remove livro especificado pelo nó
NoLivro* getLivro(NoLivro* header, char* titulo);       //retorna um livro pelo título
NoLivro* getLivroCod(NoLivro* header, int cod);     //retorna um livro pelo cod
int setQtde(NoLivro* no, int qtde);     //altera a quantidade de livros disponíveis manualmente
int freeListaLivro(NoLivro* header);        //libera a lista


#endif