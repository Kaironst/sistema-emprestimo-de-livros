# Introdução

Este é um trabalho realizado por Pedro Novak Wosch e Bruno Kussen, referente à disciplina de Estrutura de Dados da UFPR, dirigido pelo professor Helcio Soares Padilha Junior.

Aqui foi realizado a implementação de um sistema de empréstimo de livros de uma biblioteca, sendo navegada e controlada por meio do arquivo main.c, que apresenta um menu disponibilizando:    

- cadastro de livros e usuários,
- realização de empréstimos,
- devolução de livros,
- listagem de livros emprestados por um usuário,
- exibição de fila de espera de um determinado livro. 
- busca de livro pro título. 
- busca de usuário por nome. 

# Instrução de sistema
Ao iniciar o arquivo main.c, o usuário verá o seguinte menu:
``` c
=== Sistema de Empréstimo de Livros ===
"1. Cadastrar usuário"
"2. Cadastrar livro"
"3. Realizar empréstimo"
"4. Devolver livro"
"5. Listar livros emprestados por usuário"
"6. Exibir fila de espera de um livro"
"7. Buscar Livro por Título"
"8. Buscar Usuário por nome"
"0. Sair"
"Escolha uma opção: "
```

Após digitar o número referente a uma dessas opções no terminal, o usuário receberá novos prompts para completar a tarefa requisitada.
Um exemplo, utilizando a função 2. Cadastrar livro:

``` c

"Título do livro:"
    A Arte da Guerra
"Autor: "
    Sun Tzu
"Código do livro:"
    123456789
"Quantidade disponível:"
    1

"Livro cadastrado com sucesso"
```







