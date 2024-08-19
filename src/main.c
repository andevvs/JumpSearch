// main.c
#include <stdio.h>
#include "registerGym.c"

int main() {
    Aluno alunos[MAXALUNO];
    int numeroAlunos = 0;
    int opcao;

    do {
        printf(CIANO"\n|GymFitness|:\n"PADRAO);
        printf(AMARELO"1. Adicionar Aluno\n");
        printf("2. Buscar Aluno por ID\n");
        printf("3. Exibir Todos os Alunos\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: "PADRAO);
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int id;
                char nome[50];
                printf("Digite o ID do aluno: ");
                scanf("%d", &id);
                printf("Digite o nome do aluno: ");
                scanf(" %[^\n]s", nome);
                adicionarAluno(alunos, &numeroAlunos, id, nome);
                break;
            }
            case 2: {
                int id;
                printf("\nDigite o ID do aluno a ser buscado: \n");
                scanf("%d", &id);
                int indice = jumpSearch(alunos, numeroAlunos, id);
                if (indice != -1) {
                    printf(VERDE"\nAluno encontrado:\n"PADRAO);
                    exibirAluno(alunos[indice]);
                } else {
                    printf(VERMELHO"\nAluno com ID %d nao encontrado.\n"PADRAO, id );
                }
                break;
            }
            case 3: {
                exibirTodosAlunos(alunos, numeroAlunos);
                break;
            }
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
