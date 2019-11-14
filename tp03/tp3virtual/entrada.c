#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Pula uma linha no terminal.
*/
void endl() {
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

int verificaEntrada(int argc, char *argv[])
{
  /* 
  tp3virtual lru arquivo.log 4 128
  argc = 5
  argv[0] --> ./tp3virtual
  argv[1] --> lru
  argv[2] --> arquivo.log
  argv[3] --> 4
  argv[4] --> 128
  argv[argc] = (nil)
  */
  // string 1. o algoritmo de substituição a ser usado (lru, 2a — segunda chance —,fifo ou random);
  // string 2. o arquivo contendo a sequência de endereços de memória acessados (arquivo.log, nesse exemplo);
  // int 3. o tamanho de cada página/quadro de memória, em kilobytes — faixa de valores razoáveis: de 2 a 64;
  // int 4. o tamanho total da memória fı́sica disponı́vel para o processo, também em kilobytes — faixa de valores razoáveis: de 128 a 16384 (16 MB).
  
  int erro = 0;
  
  int erroQtdParametros = (argc != 5);
  if (erroQtdParametros)
  {
    printf("%s\n", "Erro: Quantidade de argumentos invalida");
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
  int erroArg3ForaDaFaixa = (arg3 < 2 || arg3 > 64);
  if (erroArg3ForaDaFaixa)
  {
    printf("%s\n", "Erro: Argumento 3 fora da faixa especificada (entre 2 e 64)");
    return ++erro;
  }
  
  int arg4 = atoi(argv[4]);
  int erroArg4ForaDaFaixa = (arg4 < 128 || arg4 > 16384);
  if (erroArg4ForaDaFaixa)
  {
    printf("%s\n", "Erro: Argumento 4 fora da faixa especificada (entre 128 e 16384)");
    return ++erro;
  }
  
  return erro;
}

/*
  Lê conteúdo do arquivo de entrada.
  Por enquanto, apenas printa o conteúdo na tela, sem armazenar em nenhum lugar.
*/
void lerArquivo(char *arquivo)
{
  unsigned addr;
  char rw;
  FILE* file;

  file = fopen(arquivo, "r");

  if(file == NULL)
  {
    printf("Error: Falha na abertura do arquivo");
    exit(1);
  }

  while(fscanf(file, "%x %c", &addr, &rw) == 2){
    printf("%x %c", addr, rw);
    endl();
  }

  fclose(file);
}