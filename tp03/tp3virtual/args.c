#include "args.h"
#include <string.h>
#include <time.h>

void setArgs(args* a, char* algoritmo, char* arquivo, int tamPagina, int tamTotal, int modoDebug)
{
  unsigned s, tmp;
  /* Derivar o valor de s: */
  tmp = tamPagina * 1024;
  s = 0;
  while (tmp>1)
  {
    tmp = tmp>>1;
    s++;
  }
  a->algoritmo = algoritmo;
  a->arquivo = arquivo;
  a->tamPagina = tamPagina;
  a->tamTotal = tamTotal;
  a->modoDebug = modoDebug;
  a->s = s;
  a->first = NULL;
  a->last = NULL;
}

void printArgs(args* a)
{
  printf("Arquivo de entrada: %s\nTamanho da memoria: %d KB\nTamanho das páginas: %d KB\nTecnica de reposicao: %s\n", a->arquivo, a->tamTotal, a->tamPagina, a->algoritmo);
}

void printDebug(args* a, unsigned addr, char rw)
{
  bool printAll = (a->modoDebug == 1);
  bool printR = (a->modoDebug == 2 && rw == 'R');
  bool printW = (a->modoDebug == 3 && rw == 'W');
  if (printAll || printR || printW)
  {
    printf("DEBUG: Endereco %x %c\n", addr, rw);
  }
}

void lerArquivo(args* a, stats* s)
{
  unsigned addr;
  char rw;
  int pageNumber = 0, qtde = a->tamTotal/a->tamPagina;
  bool r;
  FILE* file;
  //Abre arquivo de entrada
  file = fopen(a->arquivo, "r");
  if (file == NULL)
  {
    printf("%s\n", "Erro: Falha na abertura do arquivo");
    exit(1);
  }
  //Lê as linhas do arquivo enquanto houverem linhas.
  while(fscanf(file, "%x %c", &addr, &rw) == 2)
  {
    s->timer++;
    pageNumber = addr >> a->s;
    //Leitura de endereço
    if(rw == 'R')
    {
      r = readPage(a, addr);
      if(r)
      {
        s->acertos++;
      } else
      {
        s->erros++;
        if(s->usedPages < qtde)
        {
          addPage(a, s, addr, qtde, pageNumber);
        } else
        {
          s->pageFaults++;
          changePage(a, s, addr, qtde, pageNumber);
        }
      }
      s->leituras++;
      printDebug(a, addr, rw);
    //Escrita de endereço
    } else if(rw == 'W')
    {
      //s->escritas++;
      if(s->usedPages < qtde)
      {
        addPage(a, s, addr, qtde, pageNumber);
      } else
      {
        s->pageFaults++;
        changePage(a, s, addr, qtde, pageNumber);
      }
    }
  }
  fclose(file);
  freePages(a);
}

void addPage(args* a, stats* s, unsigned addr, int qtde, int pageNumber)
{
  //Aloca nova pagina
  page *p;
  p = malloc(sizeof(page));
  p->addr = addr;
  p->pageNumber = pageNumber;
  p->time = s->timer;
  p->prox = NULL;
  switch (s->usedPages)
  {
    case 0:
      a->first = p;
      a->last = a->first;
      break;
    default:
      a->last->prox = p;
      a->last = p;
      break;
  }
  if (s->usedPages < qtde)
  {
    s->usedPages++;
  }
  s->escritas++;
  printDebug(a, addr, 'W');
}

void changePage(args* a, stats* s, unsigned addr, int qtde, int pageNumber)
{
  //Aplica politicas de substituição
  if(strcmp(a->algoritmo, "random") == 0)
  {
    randomP(a, s, addr, pageNumber);
  } else
  {
    temporal(a, s, addr, qtde, pageNumber);
  }
  s->reEscritas++;
}

bool readPage(args* a, unsigned addr)
{
  page *p = a->first, *ant = NULL, *aux = NULL;
  //Procura endereço na tabela
  while(p != NULL)
  {
    if (p->addr == addr)
    {
      if(strcmp(a->algoritmo, "lru") == 0)
      {
        //Reposiciona elemento na lista para aplicação de lru
        if (ant == NULL)
        {
          aux = a->first;
          a->first = a->first->prox;
          free(aux);
        } else
        {
          if (p->prox != NULL)
          {
            ant->prox = p->prox;
          }
        }
        a->last->prox = p;
        a->last = p;
        p->prox = NULL;
      }
      return true;
    }
    ant = p;
    p = p->prox;
  }
  return false;
}

void temporal(args* a, stats* s, unsigned addr, int qtde, int pageNumber)
{
  addPage(a, s, addr, qtde, pageNumber);
  if (s->usedPages == qtde)
  {
    page *aux = a->first;
    a->first = a->first->prox;
    free(aux);
  }
}

void randomP(args* a, stats* s, unsigned addr, int pageNumber)
{
  int n, i;
  page *p = a->first;
  s->escritas++;
  printDebug(a, addr, 'W');
  //Nova seed para cada execução
  srand(time(NULL));
  n = rand() % s->usedPages;
  for (i = 0; i < n; i++)
  {
    p = p->prox;
  }
  p->addr = addr;
  p->pageNumber = pageNumber;
  p->time = s->timer;
}

void freePages(args* a)
{
  page* p = a->first;
  while (p != NULL)
  {
    a->first = a->first->prox;
    free(p);
    p = a->first;
  }
}
