#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define PADRAO    "\033[0m"   // costantes para adicionar cores ao codigo
#define VERMELHO  "\033[31m"      
#define VERDE     "\033[32m"     
#define AMARELO   "\033[33m"      
#define AZUL      "\033[34m"      
#define MAGENTA   "\033[35m"      
#define CIANO     "\033[36m"      
#define BRANCO    "\033[37m"      
#define MAXALUNO 500000 // constante para definir o tamanho maximo do array de alunos

// struct para armazenar informações do aluno
typedef struct aluno Aluno;

// função para adicionar um aluno
void adicionarAluno(Aluno *alunos, int* numeroAlunos, int id, char nome[]);

// função do algoritmo de busca por pulo (Jump Search) para buscar um aluno pelo seu id
int jumpSearch(Aluno *alunos, int numeroAlunos, int id);

// função pra exibir apenas um aluno
void exibirAluno(Aluno *aluno, int indice);

// função para exibir todos os alunos que foram cadastrados
void exibirTodosAlunos(Aluno *alunos, int numeroAlunos);

//função para carregar alunos a partir de um arquivo
void carregarAlunosDoArquivo(Aluno *alunos, int *numeroAlunos, const char *nomeArquivo);

//função para salvar o tempo de execução em um arquivo
void salvarTempoExecucao(const char *nomeArquivo, double tempo);

//função para alocar dinamicamente
Aluno *alocacao();