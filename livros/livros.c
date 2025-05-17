#include "livros.h"
#include <stdio.h>
#include <stdlib.h>

NoLivro* iniListaLivro() {
    NoLivro* header=(NoLivro*)malloc(sizeof(NoLivro));
    header->autor="";
    header->titulo="";
    header->cod=0;
    header->proximo=NULL;
    header->anterior=NULL;
    return header;
}

int addLivro(NoLivro* header,char* titulo, char* autor, int cod, int qtdeDisponivel) {
    NoLivro* novo=(NoLivro*)malloc(sizeof(NoLivro));
    novo->autor=autor;
    novo->titulo=titulo;
    novo->cod=cod;
    novo->qtdeDisponivel=qtdeDisponivel;
    novo->proximo=header->proximo;
    header->proximo=novo;
    novo->proximo->anterior=novo;
    return 1;
}

int rmLivro(NoLivro* no) {
    if (no==NULL || no->anterior==NULL ) return 0;     // nó não encontrado
    no->proximo->anterior=no->anterior;
    no->anterior->proximo=no->proximo;
    free(no);
    return 1;
}

NoLivro* getLivro(NoLivro* header, char* titulo) {
    NoLivro* atual=header->proximo;
    while (atual!=NULL && atual->titulo!=titulo) {
        atual=atual->proximo;
    }
    return atual;
}

NoLivro* getLivroCod(NoLivro* header, int cod) {
    NoLivro* atual=header->proximo;
    while (atual!=NULL && atual->cod!=cod) {
        atual=atual->proximo;
    }
    return atual;
}

int setQtde(NoLivro* no, int qtde) {
    no->qtdeDisponivel=qtde;
}

int freeLIstaLivro(NoLivro* header) {
while (rmLivro(header->proximo));
free(header);
}