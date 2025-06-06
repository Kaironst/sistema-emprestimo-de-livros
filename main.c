#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "usuarios/usuarios.h"
#include "livros/livros.h"
#include "emprestimos/emprestimos.h"
#include "lista/lista.h"

//print de todo o menu para facilitar
void menu() {
    printf("\n=== Sistema de Emprestimo de Livros ===\n");
    printf("1. Cadastrar usuario\n");
    printf("2. Cadastrar livro\n");
    printf("3. Realizar emprestimo\n");
    printf("4. Devolver livro\n");
    printf("5. Listar livros emprestados por usuario\n");
    printf("6. Exibir fila de espera de um livro\n");
    printf("7. Buscar Livro por Título\n");
    printf("8. Buscar Usuário por nome\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
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
                
                printf("Nome do usuario: ");
                fgets(nome, 100, stdin);
                for (int i=0; i<strlen(nome); i++) nome[i] = tolower(nome[i]);
                nome[strcspn(nome, "\n")] = 0;

                printf("RA/SIAPE: ");
                scanf("%d", &raSiape);

                printf("Tipo (0 = ALUNO, 1 = PROFESSOR): ");
                scanf("%d", &tipo);
                getchar();

                // Verificação se o usuário já existe
                NoUsuario* aux = listaUsuarios;
                int existe = 0;
                while (aux != NULL) {
                    if (aux->raSiape == raSiape) {
                    existe = 1;
                    break;
                }
                aux = aux->proximo;
            }

            if (existe==1) {
                printf("Erro: Usuario de raSiape %d ja cadastrado.\n", raSiape);
                break;
            }

                addUsuario(listaUsuarios, strdup(nome), raSiape, tipo == 0 ? ALUNO : PROFESSOR);
                printf("Usuario cadastrado com sucesso.\n");
                break;
            }

            case 2: {   //cadastro de livro
                char titulo[100], autor[100];
                int cod, qtde;
                
                printf("Titulo do livro: ");
                fgets(titulo, 100, stdin);
                for (int i=0; i<strlen(titulo); i++) titulo[i] = tolower(titulo[i]);
                titulo[strcspn(titulo, "\n")] = 0;

                printf("Autor: ");
                fgets(autor, 100, stdin);
                autor[strcspn(autor, "\n")] = 0;

                printf("Codigo do livro: ");
                scanf("%d", &cod);

                printf("Quantidade disponivel: ");
                scanf("%d", &qtde);
                getchar();
                
                // Verificação se o livro já existe
                NoLivro* aux = listaLivros;
                int existe = 0;
                while (aux != NULL) {
                    if (aux->cod == cod) {
                    existe = 1;
                    break;
                }
                aux = aux->proximo;
            }

            if (existe==1) {
                printf("Erro: Livro de codigo %d já cadastrado.\n", cod);
                break;
            }
                
                addLivro(listaLivros, strdup(titulo), strdup(autor), cod, qtde);
                printf("Livro cadastrado com sucesso.\n");
                break;
            }

            case 3: {   //realizar empréstimo
                int raSiape, cod;
                char dataEmp[11], dataDev[11];
                
                printf("RA/SIAPE do usuario: ");
                scanf("%d", &raSiape);

                printf("Codigo do livro: ");
                scanf("%d", &cod);

                printf("Data de emprestimo (dd/mm/aaaa): ");
                scanf("%s", dataEmp);

                printf("Data de devolucao (dd/mm/aaaa): ");
                scanf("%s", dataDev);

                NoUsuario* usuario = getUsuarioRaSiape(listaUsuarios, raSiape);
                NoLivro* livro = getLivroCod(listaLivros, cod);

                if (!usuario || !livro) {
                    printf("Usuario ou livro nao encontrado.\n");
                    break;
                }

                emprestarLivro(livro, usuario, dataEmp, dataDev);
                break;
            }

            case 4: {   //devolver livro
                int raSiape, cod;
                
                printf("RA/SIAPE do usuario: ");
                scanf("%d", &raSiape);

                printf("Codigo do livro: ");
                scanf("%d", &cod);

                NoUsuario* usuario = getUsuarioRaSiape(listaUsuarios, raSiape);
                NoLivro* livro = getLivroCod(listaLivros, cod);

                if (!usuario || !livro) {
                    printf("Usuario ou livro nao encontrado.\n");
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
                
                printf("RA/SIAPE do usuario: ");
                scanf("%d", &raSiape);
                NoUsuario* usuario = getUsuarioRaSiape(listaUsuarios, raSiape);

                if (!usuario) {
                    printf("Usuario não encontrado.\n");
                    break;
                }

                listarEmprestimosPorUsuario(listaLivros, usuario);
                break;
            }

            case 6: {   //exibir fila de espera de um livro
                int cod;
                
                printf("Digite o Codigo do livro: \n");
                scanf("%d", &cod);
                NoLivro* livro = getLivroCod(listaLivros, cod);

                if (!livro) {
                    printf("Livro nao encontrado.\n");
                    break;
                }

                exibirFilaEspera(livro);
                break;
            }

            case 7: { //busca livro pelo nome
                char titulo [100];

                printf("Digite o Título do Livro: \n");
                fgets(titulo, 100, stdin);
                for (int i=0; i<strlen(titulo); i++) titulo[i] = tolower(titulo[i]);
                titulo[strcspn(titulo, "\n")] = 0;
                NoLivro* livro = getLivro(listaLivros,titulo);

                if (!livro) {
                    printf("Livro nao encontrado. \n");
                    break;
                }

                printf(" Titulo: %s \n Autor: %s \n Cod: %d \n Qtde Disponível: %d \n",
                    livro->titulo, livro->autor, livro->cod, livro->qtdeDisponivel
                );

                break;
            }

            case 8: {   //busca usuario pelo nome
                char nome [100];

                printf("Digite o Nome do Usuário: \n");
                fgets(nome, 100, stdin);
                for (int i=0; i<strlen(nome); i++) nome[i] = tolower(nome[i]);
                nome[strcspn(nome, "\n")] = 0;
                NoUsuario* usuario = getUsuario(listaUsuarios, nome);

                if (!usuario) {
                    printf("Usuario nao encontrado. \n");
                    break;
                }

                printf(" Nome: %s \n Ra/Siape: %d \n Numero de Empréstimos: %d \n Professor?: %d \n",
                usuario->nome, usuario->raSiape, usuario->numEmprestimos, usuario->tipoUsuario
                );
                
                break;
            }

            case 0:{
                
                printf("Encerrando o sistema...\n");
                break;

            default:
                
                printf("Opcao invalida. Tente novamente.\n");
                break;
            }

        }
    } while (opcao != 0);

    // Liberação de memória
    freeListaLivro(listaLivros);
    freeListaUsuario(listaUsuarios);

    return 0;
}