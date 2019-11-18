#include "args.h"

//Pula uma linha no terminal
void endl();

//Verifica se uma string ls ocorre no vetor de strings set, com len posicoes.
int strcontains(const char *ls, char *set[], int len);

//Verifica formato dos parâmetros de entrada do programa e seta valores.
int setEntrada(int argc, char *argv[], args* a);
