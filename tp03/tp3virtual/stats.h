struct estatisticas
{
  int nPaginasLidas;
  int nPaginasEscritas;
};

typedef struct estatisticas stats;

void setStats(stats* s, int nPaginasLidas, int nPaginasEscritas);
void printStats(stats* s);
