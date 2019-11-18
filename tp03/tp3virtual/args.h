struct argumentos
{
  char* algoritmo;
  char* arquivo;
  int tamPagina;
  int tamTotal;
  unsigned s;
  struct page* first;
  struct page* last;
};

typedef struct argumentos args;

void setArgs(args* a, char* algoritmo, char* arquivo, int tamPagina, int tamTotal);

void printArgs(args* a);
