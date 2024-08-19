#include <stdio.h>
#include <time.h>
#include "registerGymtime.c"

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

                // medir o tempo de execução usando a biblioteca time.h
                clock_t inicio = clock();
                int indice = jumpSearch(alunos, numeroAlunos, id);
                clock_t fim = clock();
                double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

                if (indice != -1) {
                    printf(VERDE"\nAluno encontrado:\n"PADRAO);
                    exibirAluno(alunos[indice]);
                } else {
                    printf(VERMELHO"\nAluno com ID %d nao encontrado.\n"PADRAO, id );
                }

                // tempo de execução
                printf(AMARELO"\nTempo de execucao: %.6f segundos\n"PADRAO, tempo_execucao);
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
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
