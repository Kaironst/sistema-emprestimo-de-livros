#ifndef LISTA_USUARIOS
#define LISTA_USUARIOS

typedef enum {
ALUNO,
PROFESSOR
} tipoUsuario;

typedef struct NO_USUARIO {
    char* nome;
    int raSiape;
    tipoUsuario tipoUsuario;
    struct NO_USUARIO* proximo;
    struct NO_USUARIO* anterior;
}NoUsuario;

NoUsuario* iniListaUsuario();
int addUsuario(NoUsuario* header, char* nome, int raSiape, tipoUsuario tipoUsuario);
int rmUsuario(NoUsuario* no);
NoUsuario* getUsuario(NoUsuario* header, char* nome);
NoUsuario* getUsuarioRaSiape(NoUsuario* header, int raSiape);
int freeListaUsuario(NoUsuario* header);

#endif