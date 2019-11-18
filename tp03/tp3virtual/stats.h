struct estatisticas
{
  int nPaginasLidas;
  int nPaginasEscritas;
  int usedPages;
  int timer;
  int escritas;
  int reEscritas;
};

typedef struct estatisticas stats;

void setStats(stats* s, int nPaginasLidas, int nPaginasEscritas);
void printStats(stats* s);
