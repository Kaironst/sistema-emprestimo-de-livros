#include "usuarios.h"
#include <stdio.h>
#include <stdlib.h>

NoUsuario* iniListaUsuario() {
    NoUsuario* header=(NoUsuario*)malloc(sizeof(NoUsuario));
    header->nome="";
    header->raSiape=0;
    header->tipoUsuario=ALUNO;
    header->proximo=NULL;
    header->anterior=NULL;
    return header;
}

int addUsuario(NoUsuario* header, char* nome, int raSiape, tipoUsuario tipoUsuario) {
    NoUsuario* novo=(NoUsuario*)malloc(sizeof(NoUsuario));
    novo->nome=nome;
    novo->raSiape=raSiape;
    novo->tipoUsuario=tipoUsuario;
    novo->proximo=header->proximo;
    header->proximo=novo;
    novo->proximo->anterior=novo;
}

int rmUsuario(NoUsuario* no) {
    if (no==NULL || no->anterior==NULL) return 0;     // nó não encontrado
    no->proximo->anterior=no->anterior;
    no->anterior->proximo=no->proximo;
    free(no);
    return 1;
}

NoUsuario* getUsuario(NoUsuario* header, char* nome) {
    NoUsuario* atual=header->proximo;
    while(atual!=NULL && atual->nome!=nome) {
        atual=atual->proximo;
    }
    return atual;
}

NoUsuario* getUsuarioRaSiape(NoUsuario* header, int raSiape) {
    NoUsuario* atual=header->proximo;
    while(atual!=NULL && atual->raSiape!=raSiape) {
        atual=atual->proximo;
    }
    return atual;
}

int freeListaUsuario(NoUsuario* header) {
    while(rmUsuario(header->proximo));
    free(header);
}