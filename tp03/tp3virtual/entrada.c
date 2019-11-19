#include "entrada.h"
#include <string.h>

/*
  Pula uma linha no terminal.
*/
void endl()
{
  printf("%s", "\n");
}

/*
  Verifica se uma string ls ocorre no vetor de strings set, com len posicoes.
*/
int strcontains(const char *ls, char *set[], int len)
{
  int contem;
  int i;
  for (i = 0; i < len; ++i)
  {
    contem = strcmp(ls, set[i]);
    if (contem == 0)
    {
      return contem;
    }
  }
  return contem;
}

int setEntrada(int argc, char *argv[], args* a)
{
  int erro = 0;
  int erroQtdParametros = (argc < 5 || argc > 6);
  if (erroQtdParametros)
  {
    printf("%s\n%s\n", "Erro: Quantidade de argumentos invalida, insira 4 ou 5 argumentos", \
    "Para usar o modo debug, adicione o numero 1 como ultimo argumento");
    return ++erro;
  }
  char *arg1 = argv[1];
  char *arg1Validos[] = {"lru", "2a", "fifo", "random"};
  int erroArg1Invalido = (strcontains(arg1, arg1Validos, 4) != 0);
  if (erroArg1Invalido)
  {
    printf("%s - %s\n%s: ", "Erro: Argumento 1 invalido", arg1, "Opcoes validas");
    int i;
    for (i = 0; i < 4; ++i)
    {
      printf("%s ", arg1Validos[i]);
    }
    endl();
    return ++erro;
  }
  char *arg2 = argv[2];
  int erroArg2Invalido = (strlen(arg2) < 1);
  if (erroArg2Invalido)
  {
    printf("%s\n", "Erro: Nome de arquivo invalido");
    return ++erro;
  }
  int arg3 = atoi(argv[3]);
  // int erroArg3ForaDaFaixa = (arg3 < 2 || arg3 > 64);
  int erroArg3ForaDaFaixa = (arg3 < 2);
  if (erroArg3ForaDaFaixa)
  {
    // printf("%s\n", "Erro: Argumento 3 fora da faixa especificada (entre 2 e 64)");
    printf("%s\n", "Erro: Argumento 3 fora da faixa especificada (a partir de 2; recomendado: entre 2 e 64)");
    return ++erro;
  }
  int arg4 = atoi(argv[4]);
  // int erroArg4ForaDaFaixa = (arg4 < 128 || arg4 > 16384);
  int erroArg4ForaDaFaixa = (arg4 < 128);
  if (erroArg4ForaDaFaixa)
  {
    // printf("%s\n", "Erro: Argumento 4 fora da faixa especificada (entre 128 e 16384)");
    printf("%s\n", "Erro: Argumento 4 fora da faixa especificada (a partir de 128; recomendado: entre 128 e 16384)");
    return ++erro;
  }
  // Modo debug
  int arg5 = 0;
  if (argc == 6)
  {
    arg5 = atoi(argv[5]);
  }
  setArgs(a, arg1, arg2, arg3, arg4, arg5);
  return erro;
}
