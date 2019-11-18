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
  printf("Paginas lidas: %d\nPaginas escritas: %d\n", s->pageFaults, s->reEscritas);
}
