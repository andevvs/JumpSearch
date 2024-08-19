#include <stdio.h>
#include <string.h>
#include <math.h>
#include "registerGym.h"

void adicionarAluno(Aluno alunos[], int* numeroAlunos, int id, char nome[]) {
    if (*numeroAlunos >= MAXALUNO) {
        printf("\nNao eh possivel adicionar mais alunos.\n");
        return;
    }
    alunos[*numeroAlunos].id = id;
    strcpy(alunos[*numeroAlunos].nome, nome);
    (*numeroAlunos)++;
    printf(VERDE"\nAluno adicionado com sucesso!\n"PADRAO);
}

int jumpSearch(Aluno alunos[], int numeroAlunos, int id) {
    int tamanhoBloco = (int)sqrt(numeroAlunos); 
    int inicioBlocoAnterior = 0;

    // ira encontrar o bloco onde o elemento possa estar presente
    while (alunos[(tamanhoBloco < numeroAlunos ? tamanhoBloco : numeroAlunos) - 1].id < id) {
        inicioBlocoAnterior = tamanhoBloco;
        tamanhoBloco += (int)sqrt(numeroAlunos); 
        if (inicioBlocoAnterior >= numeroAlunos)
            return -1; // se inicioBlocoAnterior ultrapassar o número de alunos, o ID nao estara presente
    }

    // realiza a busca linear dentro do bloco
    for (int i = inicioBlocoAnterior; i < (tamanhoBloco < numeroAlunos ? tamanhoBloco : numeroAlunos); i++) {
        if (alunos[i].id == id)
            return i; // ID encontrado
    }

    return -1; // Elemento não encontrado
}

void exibirAluno(Aluno aluno) {
    printf("\nID: %d\nNome: %s\n", aluno.id, aluno.nome);
}

void exibirTodosAlunos(Aluno alunos[], int numeroAlunos) {
    if (numeroAlunos == 0) {
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }
    for (int i = 0; i < numeroAlunos; i++) {
        printf("\n%d. ", i + 1);
        exibirAluno(alunos[i]);
    }
}