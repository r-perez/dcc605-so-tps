#include "args.h"
#include <stdio.h>

void setArgs(args* a, char* algoritmo, char* arquivo, int tamPagina, int tamTotal, int modoDebug)
{
  unsigned s, tmp;
  /* Derivar o valor de s: */
  tmp = tamPagina * 1024;
  s = 0;
  while (tmp>1)
  {
    tmp = tmp>>1;
    s++;
  }
  a->algoritmo = algoritmo;
  a->arquivo = arquivo;
  a->tamPagina = tamPagina;
  a->tamTotal = tamTotal;
  a->modoDebug = modoDebug;
  a->s = s;
}

void printArgs(args* a)
{
  printf("Arquivo de entrada: %s\nTamanho da memoria: %d KB\nTamanho das páginas: %d KB\nTecnica de reposicao: %s\n", a->arquivo, a->tamTotal, a->tamPagina, a->algoritmo);
}
