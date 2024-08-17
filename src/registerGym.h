#define MAX 100 // constante para definir o tamanho maximo do array de alunos

// struct para armazenar informações do aluno
typedef struct {
    int id;
    char nome[50];
} Aluno;

// função para adicionar um aluno
void adicionarAluno(Aluno alunos[], int* numeroAlunos, int id, char nome[]);