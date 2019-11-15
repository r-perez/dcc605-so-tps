#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Pula uma linha no terminal
void endl();

//Verifica se uma string ls ocorre no vetor de strings set, com len posicoes.
int strcontains(const char *ls, char *set[], int len);

//Verifica formato dos parâmetros de entrada do programa.
int verificaEntrada(int argc, char *argv[]);

//Lê conteúdo do arquivo de entrada.
void lerArquivo(char *arquivo);