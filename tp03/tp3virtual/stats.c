#include "stats.h"
#include <stdio.h>

void setStats(stats* s, int nPaginasLidas, int nPaginasEscritas)
{
  s->nPaginasLidas = nPaginasLidas;
  s->nPaginasEscritas = nPaginasEscritas;
}

void printStats(stats* s)
{
  printf("Paginas lidas: %d\nPaginas escritas: %d\n", s->nPaginasLidas, s->nPaginasEscritas);
}
