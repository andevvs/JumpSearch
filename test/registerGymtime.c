#include "registerGymtime.h"
struct aluno{
    int id;
    char nome[50];
};

void adicionarAluno(Aluno *alunos, int *numeroAlunos, int id, char nome[]) {
    alunos[*numeroAlunos].id = id;
    strcpy(alunos[*numeroAlunos].nome, nome);
    (*numeroAlunos)++;
}

void exibirAluno(Aluno aluno) {
    printf("ID: %d, Nome: %s\n", aluno.id, aluno.nome);
}

void exibirTodosAlunos(Aluno *alunos, int numeroAlunos) {
    for (int i = 0; i < numeroAlunos; i++) {
        exibirAluno(alunos[i]);
    }
}

int jumpSearch(Aluno *alunos, int numeroAlunos, int idProcurado) {
    int pulo = sqrt(numeroAlunos);
    int blocoInicial = 0;
    int blocoFinal = pulo;

    while (alunos[blocoFinal - 1].id < idProcurado && blocoFinal < numeroAlunos) {
        blocoInicial = blocoFinal;
        blocoFinal += pulo;
        if (blocoFinal > numeroAlunos) {
            blocoFinal = numeroAlunos;
        }
    }

    for (int i = blocoInicial; i < blocoFinal; i++) {
        if (alunos[i].id == idProcurado) {
            return i;
        }
    }

    return -1;
}

void carregarAlunosDoArquivo(Aluno *alunos, int *numeroAlunos, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
        return;
    }

    int id;
    char nome[50];
    while (fscanf(arquivo, "%d %49[^\n]", &id, nome) != EOF) {
        adicionarAluno(alunos, numeroAlunos, id, nome);
    }

    fclose(arquivo);
}

void salvarTempoExecucao(const char *nomeArquivo, double tempo) {
    FILE *arquivo = fopen(nomeArquivo, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s para salvar o tempo de execução.\n", nomeArquivo);
        return;
    }

    fprintf(arquivo, "Tempo de execução: %.6f segundos\n", tempo);
    fclose(arquivo);
}
