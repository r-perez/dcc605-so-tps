#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "args.h"
#include "stats.h"
#include "page.h"

void addPage(args* a, stats* s, unsigned addr, int qtde, int pageNumber)
{
  page *p = (page*)malloc(sizeof(page));

  p->addr = addr;
  p->pageNumber = pageNumber;
  p->time = s->timer;
  p->prox = NULL;

  switch(s->usedPages){
    case 0:
      a->first = p;
      a->last = a->first;
      break;
    default:
      a->last->prox = p;
      a->last = p;
      break;
  }

  if(s->usedPages < qtde){
    s->usedPages++;
  }

  s->escritas++;
}

void changePage(args* a, stats* s, unsigned addr)
{
  if(strcmp(a->algoritmo, "lru") == 0){
    //lru(addr);
  }
  else if(strcmp(a->algoritmo, "fifo") == 0){
    //fifo(addr);
  }
  else if(strcmp(a->algoritmo, "random") == 0){
    //random(addr);
  }
  s->reEscritas++;
}

bool readPage(args* a, unsigned addr)
{
  page *p = a->first, *ant = NULL, *aux = NULL;

  while(p != NULL){
    if(p->addr == addr){

      if(strcmp(a->algoritmo, "lru") == 0){

        if(ant == NULL){
          aux = a->first;
          a->first = a->first->prox;
          free(aux);
        } else {
          if(p->prox != NULL){
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

/*
  Lê conteúdo do arquivo de entrada.
*/
void lerArquivo(args* a, stats* s)
{
  unsigned addr;
  char rw;
  int pageNumber = 0, qtde = a->tamTotal/a->tamPagina;
  bool r;
  FILE* file;

  file = fopen(a->arquivo, "r");

  if(file == NULL){
    printf("%s\n", "Erro: Falha na abertura do arquivo");
    exit(1);
  }

  //Lê as linhas do arquivo enquanto houverem linhas.
  while(fscanf(file, "%x %c", &addr, &rw) == 2)
  {
    s->timer++;

    pageNumber = addr >> a->s;

    if(rw == 'R'){
      r = readPage(a, addr);
      if(r){
        s->acertos++;
      } else {
        s->erros++;
        if(s->usedPages < qtde){
          addPage(a, s, addr, qtde, pageNumber);
        }
        else{
          s->pageFaults++;
          changePage(a, s, addr);
        }
      }
    } else if(rw == 'W') {
      if(s->usedPages < qtde){
        addPage(a, s, addr, qtde, pageNumber);
      }
      else{
        s->pageFaults++;
        changePage(a, s, addr);
      }
    }
  }

  fclose(file);
}