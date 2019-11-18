struct estatisticas
{
  int nPaginasLidas;
  int reEscritas;
  int usedPages;
  int timer;
  int escritas;
};

typedef struct estatisticas stats;

void setStats(stats* s, int nPaginasLidas, int reEscritas);

void printStats(stats* s);
