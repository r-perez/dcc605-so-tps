#include "stats.h"
#include <stdio.h>

void setStats(stats* s)
{
  s->pageFaults = 0;
  s->reEscritas = 0;
  s->usedPages = 0;
  s->timer = 0;
  s->escritas = 0;
  s->leituras = 0;
  s->acertos = 0;
  s->erros = 0;
}

void printStats(stats* s)
{
  printf("Total de acessos: %d\n", s->timer);
  printf("Operações de leitura: %d\nOperações de escrita: %d\n", s->leituras, s->escritas);
  printf("Hits: %d\nMisses: %d\n", s->acertos, s->erros);
  printf("Writebacks: %d\n", s->reEscritas);
}
