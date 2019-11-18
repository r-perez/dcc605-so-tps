#include "stats.h"
#include <stdio.h>

void setStats(stats* s, int nPaginasLidas, int reEscritas)
{
  s->nPaginasLidas = nPaginasLidas;
  s->reEscritas = reEscritas;
  s->usedPages = 0;
  s->timer = 0;
  s->escritas = 0;
}

void printStats(stats* s)
{
  printf("Paginas lidas: %d\nPaginas escritas: %d\n", s->nPaginasLidas, s->reEscritas);
}
