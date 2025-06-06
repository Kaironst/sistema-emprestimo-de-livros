#include "usuarios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    if (novo->proximo!=NULL)
        novo->proximo->anterior=novo;
    return 1;
}

int rmUsuario(NoUsuario* no) {
    if (no==NULL || no->anterior==NULL) return 0;     // nó não encontrado
    free(no->nome);
    no->proximo->anterior=no->anterior;
    no->anterior->proximo=no->proximo;
    free(no);
    no=NULL;
    return 1;
}

NoUsuario* getUsuario(NoUsuario* header, char* nome) {
    NoUsuario* atual=header->proximo;
    while( atual!=NULL && strcmp(atual->nome,nome)!=0 ) {
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
    header=NULL;
    return 1;
}