#include <stdio.h>
#include <string.h>
#include <math.h>
#include "registerGym.h"

void adicionarAluno(Aluno alunos[], int* numeroAlunos, int id, char nome[]) {
    if (*numeroAlunos >= MAX) {
        printf("Não é possível adicionar mais alunos.\n");
        return;
    }
    alunos[*numeroAlunos].id = id;
    strcpy(alunos[*numeroAlunos].nome, nome);
    (*numeroAlunos)++;
    printf("Aluno adicionado com sucesso!\n");
}
