/*
  tp3virtual lru arquivo.log 4 128
  argc = 5
  argv[0] --> ./tp3virtual
  argv[1] --> lru
  argv[2] --> arquivo.log
  argv[3] --> 4
  argv[4] --> 128
  argv[argc] = (nil)
*/
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
