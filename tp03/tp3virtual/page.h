struct pagina
{
  unsigned addr;
  int pageNumber;
  int time;
  struct pagina* prox;
};

typedef struct pagina page;
