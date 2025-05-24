#include <stdio.h>
#include <stdlib.h>
#include "emprestimos/emprestimos.h"
#include "lista/lista.h"
#include "livros/livros.h"
#include "usuarios/usuarios.h"

/*
a fazer
criar .h do emprestimo
criar .c do emprestimo
criar .h da fila
criar .c da fila
inteligar todas as listas entre si
*/



int main() {
    int opcao=-1, opcao2=-1;
    while (opcao!=0) {
        printf("==Sistema de Emprestimos de Livros=============\n");
        printf("0. Sair\n");
        printf("1. Emprestimo de livros\n");
        printf("2. Lista de espera\n");
        printf("3. Cadastro de Usuarios\n");
        printf("4. Cadastro de Livros\n");
        printf("===============================================\n");
        
        scanf("%i",&opcao);
        
        switch(opcao) {

            case 1:
                while (opcao2!=0) {
                    printf("==Emprestimo de Livros=========================\n");
                    printf("0. Voltar\n");
                    printf("1. Emprestar Livro");
                    printf("2. Devolver Livro");
                    printf("3. Visualizar Emprestimos");
                    printf("===============================================\n");
                    scanf("%i",&opcao2);
                }

                break;
            case 2:
                while (opcao2!=0) {
                    printf("==Lista de Espera============================\n");
                    printf("0. Voltar\n");
                    printf("1. Visualizar lista de espera\n");
                    printf("2. \n");
                    printf("===============================================\n");
                    scanf("%i",&opcao2);
                    scanf("%i",&opcao2);
                }

                break;
            case 3:
                while (opcao2!=0) {
                    printf("==Cadastro de Usuarios=========================\n");
                    printf("0. Voltar\n");
                    printf("1. Buscar por usuário\n");
                    printf("2. Cadastrar Usuário\n");
                    printf("3. Remover Usuário\n");
                    printf("===============================================\n");
                    scanf("%i",&opcao2);
                }

                break;
            case 4:
                while (opcao2!=0) {
                    printf("==Cadastro de livros===========================\n");
                    printf("0. Voltar\n");
                    printf("1. Buscar por Livro\n");
                    printf("2. Adicionar Novo Livro\n");
                    printf("3. Alterar Quantia em Estoque\n");
                    printf("4. Remover Livro\n");
                    printf("===============================================\n");
                    scanf("%i",&opcao2);
                }

                break;
            default:
                if (opcao!=0)
                    printf("opção inválida\n");
                break;

        }
    }
}
