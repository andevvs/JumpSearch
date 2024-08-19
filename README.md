<div>
<img align="right" width="110" height="170" src="https://assecom.ufersa.edu.br/wp-content/uploads/sites/24/2014/09/PNG-bras%C3%A3o-Ufersa.png">
<br>
<h1 align="center" style="font-weight: bold;">Busca por Pulo (Jump Search) 💻</h1>
<p align="center">
    <a href="#tech">Tecnologias</a> •
    <a href="#about">Sobre o Algoritmo</a> •
    <a href="#complexity">Complexidade</a> •
    <a href="#config">Configs de Teste</a> •
    <a href="#colab">Cotribuidores</a> 
</p>

<div>
  <h2 id="tech" style="font-weight: bold; font-size: 2rem">Tecnologia Utilizada</h2> 
  <img align="center" alt="python" src="https://img.shields.io/badge/C-FFFFFF?style=for-the-badge&logo=c&logoColor=black"/>

  <h2 id="about" style="font-weight: bold; font-size: 2rem">Sobre o Algoritmo</h2>

O Jump Search é um algoritmo de busca utilizado em arrays ou listas ordenadas. Ele opera saltando blocos de elementos em vez de percorrer cada elemento individualmente.
## Como Funciona

-Salto Inicial: O algoritmo começa verificando elementos em saltos fixos de tamanho √n (onde n é o número de elementos na lista). Isso significa que ele pula de um elemento a outro, em vez de examinar cada um sequencialmente.

-Busca Linear: Quando o algoritmo encontra um intervalo onde o elemento procurado pode estar (ou seja, onde o elemento no final do salto é maior ou igual ao valor procurado), ele realiza uma busca linear dentro desse intervalo para encontrar o elemento exato.

-Eficiência: O Jump Search é mais eficiente do que a busca linear para listas grandes, pois reduz o número de comparações necessárias ao limitar a busca linear a blocos menores.

![busca por pulo](https://harkishen-singh.github.io/jump-search-visualisation/this.gif)

## Implementação

```
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
```

## Como rodar na minha maquina?

Primeiro Clone o repositorio na sua maquina:

```bash
git clone https://github.com/andevvs/JumpSearch
```

Para executar você precisa navegar até o diretório onde o arquivo c se encontra, e no terminal use este comando:

```
gcc main.c -o main && ./main
```

  <h2 id="complexity" style="font-weight: bold; font-size: 2rem">Complexidade</h2>

### Pior Caso:

O pior caso ocorre quando o elemento procurado está no final do array ou não está presente, obrigando o algoritmo a verificar todos os blocos e realizar uma busca linear completa no último bloco. Portanto, a complexidade para o pior caso é O(√n).

```
c1 * 1 + c2 * 1 + c3 + n + c5 * n + c6 * n + c7 * n + c8 * n + c9 * 1 = O(√n)
```

### Melhor Caso:

O melhor caso ocorre quando o elemento procurado está no início do array, e o algoritmo encontra o elemento imediatamente após o primeiro salto. Portanto, a complexidade para o melhor caso é O(1).

```
c1 * 1 + c2 * 1 + c3 * 1 + c4 * 1 + c5 * 1 + c6 * 1 + c7 * 1 + c8 * 1 + c9 * 1 = O(1)
```

  <h2 id="config" style="font-weight: bold; font-size: 2rem">Configuração utilizada nos testes</h2>
  CPU: AMD Ryzen 5 5600H</br>
  Frequência: 3.5GHz até 4.4GHz</br>
  RAM: 8gb DDR4</br>
  
  <h2 id="colab" style="font-weight: bold; font-size: 2rem">Contribuidores</h2>
 
  <table>
    <tr>
      <td align="center">
        <a href="#">
          <img src="https://avatars.githubusercontent.com/u/150745935?v=4" width="100px;" alt="Fernanda Kipper Profile Picture"/><br>
          <sub>
            <a href="https://github.com/andevvs"><b>Andrei Vieira</b></a>
          </sub>
        </a>
      </td>
          </sub>
        </a>
      </td>
      <td align="center">
        <a href="#">
        </a>
      </td>
      <td align="center">
        <a href="#">
          <img src="https://avatars.githubusercontent.com/u/144806270?v=4" width="100px;" alt="Foto do Steve Jobs"/><br>
            <sub>
              <a href="https://github.com/alissonricarte"><b>Alisson ricarte</b></a>
            </sub>
        </a>
      </td>
    </tr>
  </table>
</div>