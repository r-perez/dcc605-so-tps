#include "args.h"
#include <stdio.h>

void setArgs(args* a, char* algoritmo, char* arquivo, int tamPagina, int tamTotal)
{
  a->algoritmo = algoritmo;
  a->arquivo = arquivo;
  a->tamPagina = tamPagina;
  a->tamTotal = tamTotal;
}

void printArgs(args* a)
{
  printf("%s %s %d %d\n", a->algoritmo, a->arquivo, a->tamPagina, a->tamTotal);
}
