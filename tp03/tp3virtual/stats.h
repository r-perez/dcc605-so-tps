struct estatisticas
{
  int pageFaults;
  int reEscritas;
  int usedPages;
  int timer;
  int escritas;
  int leituras;
  int acertos;
  int erros;
};

typedef struct estatisticas stats;

void setStats(stats* s);

void printStats(stats* s);
