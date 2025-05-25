#ifndef LISTA_USUARIOS
#define LISTA_USUARIOS

typedef enum {
ALUNO,
PROFESSOR
} tipoUsuario;

typedef struct NO_USUARIO {
    char* nome;
    int raSiape;
    int numEmprestimos;
    tipoUsuario tipoUsuario;
    struct NO_USUARIO* proximo;
    struct NO_USUARIO* anterior;
}NoUsuario;     //implementação da lista duplamente encadeada com cabeçalho

NoUsuario* iniListaUsuario();   //cria lista
int addUsuario(NoUsuario* header, char* nome, int raSiape, tipoUsuario tipoUsuario);
int rmUsuario(NoUsuario* no); //remove usuario da lista
NoUsuario* getUsuario(NoUsuario* header, char* nome);       //procura usuario por nome
NoUsuario* getUsuarioRaSiape(NoUsuario* header, int raSiape);       //procura usuario por rasiape
int freeListaUsuario(NoUsuario* header);        //libera a lista

#endif