#include <stdio.h>
#include <string.h>
#include <math.h>
#include "registerGym.h"

void adicionarAluno(Aluno alunos[], int* n, int id, char nome[]) {
    if (*n >= MAX) {
        printf("Não é possível adicionar mais alunos.\n");
        return;
    }
    alunos[*n].id = id;
    strcpy(alunos[*n].nome, nome);
    (*n)++;
    printf("Aluno adicionado com sucesso!\n");
}
