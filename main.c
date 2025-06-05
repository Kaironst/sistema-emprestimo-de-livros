#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "usuarios/usuarios.h"
#include "livros/livros.h"
#include "emprestimos/emprestimos.h"
#include "lista/lista.h"

//print de todo o menu para facilitar
void menu() {
    printf("\n=== Sistema de Empréstimo de Livros ===\n");
    printf("1. Cadastrar usuário\n");
    printf("2. Cadastrar livro\n");
    printf("3. Realizar empréstimo\n");
    printf("4. Devolver livro\n");
    printf("5. Listar livros emprestados por usuário\n");
    printf("6. Exibir fila de espera de um livro\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    NoUsuario* listaUsuarios = iniListaUsuario();
    NoLivro* listaLivros = iniListaLivro();

    int opcao;
    do {
        menu();
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: {   //cadastrar usuario
                char nome[100];
                int raSiape, tipo;

                printf("Nome do usuário: ");
                fgets(nome, 100, stdin);
                nome[strcspn(nome, "\n")] = 0;

                printf("RA/SIAPE: ");
                scanf("%d", &raSiape);

                printf("Tipo (0 = ALUNO, 1 = PROFESSOR): ");
                scanf("%d", &tipo);
                getchar();

                addUsuario(listaUsuarios, strdup(nome), raSiape, tipo == 0 ? ALUNO : PROFESSOR);
                printf("Usuário cadastrado com sucesso.\n");
                break;
            }

            case 2: {   //cadastro de livro
                char titulo[100], autor[100];
                int cod, qtde;

                printf("Título do livro: ");
                fgets(titulo, 100, stdin);
                titulo[strcspn(titulo, "\n")] = 0;

                printf("Autor: ");
                fgets(autor, 100, stdin);
                autor[strcspn(autor, "\n")] = 0;

                printf("Código do livro: ");
                scanf("%d", &cod);

                printf("Quantidade disponível: ");
                scanf("%d", &qtde);
                getchar();

                addLivro(listaLivros, strdup(titulo), strdup(autor), cod, qtde);
                printf("Livro cadastrado com sucesso.\n");
                break;
            }

            case 3: {   //realizar empréstimo
                int raSiape, cod;
                char dataEmp[11], dataDev[11];

                printf("RA/SIAPE do usuário: ");
                scanf("%d", &raSiape);

                printf("Código do livro: ");
                scanf("%d", &cod);

                printf("Data de empréstimo (dd/mm/aaaa): ");
                scanf("%s", dataEmp);

                printf("Data de devolução (dd/mm/aaaa): ");
                scanf("%s", dataDev);

                NoUsuario* usuario = getUsuarioRaSiape(listaUsuarios, raSiape);
                NoLivro* livro = getLivroCod(listaLivros, cod);

                if (!usuario || !livro) {
                    printf("Usuário ou livro não encontrado.\n");
                    break;
                }

                emprestarLivro(livro, usuario, dataEmp, dataDev);
                break;
            }

            case 4: {   //devolver livro
                int raSiape, cod;
                printf("RA/SIAPE do usuário: ");
                scanf("%d", &raSiape);

                printf("Código do livro: ");
                scanf("%d", &cod);

                NoUsuario* usuario = getUsuarioRaSiape(listaUsuarios, raSiape);
                NoLivro* livro = getLivroCod(listaLivros, cod);

                if (!usuario || !livro) {
                    printf("Usuário ou livro não encontrado.\n");
                    break;
                }

                if (devolverLivro(livro, usuario)) {
                    printf("Livro devolvido com sucesso.\n");
                } else {
                    printf("Erro ao devolver o livro.\n");
                }
                break;
            }

            case 5: {   //listar livros emprestados pelo usuário
                int raSiape;
                printf("RA/SIAPE do usuário: ");
                scanf("%d", &raSiape);
                NoUsuario* usuario = getUsuarioRaSiape(listaUsuarios, raSiape);

                if (!usuario) {
                    printf("Usuário não encontrado.\n");
                    break;
                }

                listarEmprestimosPorUsuario(listaLivros, usuario);
                break;
            }

            case 6: {   //exibir fila de espera de um livro
                int cod;
                printf("Código do livro: ");
                scanf("%d", &cod);
                NoLivro* livro = getLivroCod(listaLivros, cod);

                if (!livro) {
                    printf("Livro não encontrado.\n");
                    break;
                }

                exibirFilaEspera(livro);
                break;
            }

            case 0:{
                printf("Encerrando o sistema...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
            }

        }
    } while (opcao != 0);

    // Liberação de memória
    freeListaLivro(listaLivros);
    freeListaUsuario(listaUsuarios);

    return 0;
}