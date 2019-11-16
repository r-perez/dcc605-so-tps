#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entrada.h"
#include "stats.h"

/*
  Lê conteúdo do arquivo de entrada.
  Por enquanto, apenas printa o conteúdo na tela, sem armazenar em nenhum lugar.
*/
void lerArquivo(args* a)
{
  unsigned addr;
  char rw;
  FILE* file;

  file = fopen(a->arquivo, "r");

  if(file == NULL)
  {
    printf("%s\n", "Erro: Falha na abertura do arquivo");
    exit(1);
  }

  //Lê as linhas do arquivo enquanto houverem linhas.
  //O nº 2 é a quantidade de parametros lidos com sucesso pelo scanf em cada linha do arquivo
  while(fscanf(file, "%x %c", &addr, &rw) == 2)
  {
    printf("%x %c", addr, rw);
    endl();
    printf("Página: %d", addr >> a->s);
    endl();
  }

  fclose(file);
}