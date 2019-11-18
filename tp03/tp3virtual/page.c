#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "args.h"
#include "stats.h"
#include "page.h"

void lerArquivo(args* a, stats* s)
{
  unsigned addr;
  char rw;
  int pageNumber = 0, qtde = a->tamTotal/a->tamPagina;
  bool r;
  FILE* file;

  //Abre arquivo de entrada
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

    //Leitura de endereço
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
          changePage(a, s, addr, qtde, pageNumber);
        }
      }
    //Escrita de endereço
    } else if(rw == 'W') {
      if(s->usedPages < qtde){
        addPage(a, s, addr, qtde, pageNumber);
      }
      else{
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

void changePage(args* a, stats* s, unsigned addr, int qtde, int pageNumber)
{
  if(strcmp(a->algoritmo, "random") == 0){

  } else {
    temporal(a, s, addr, qtde, pageNumber);
  }

  s->reEscritas++;
}

bool readPage(args* a, unsigned addr)
{
  page *p = a->first, *ant = NULL, *aux = NULL;

  //Procura endereço na tabela
  while(p != NULL){
    if(p->addr == addr){

      if(strcmp(a->algoritmo, "lru") == 0){

        //Reposiciona elemento na lista para aplicação de lru
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

void temporal(args* a, stats*s, unsigned addr, int qtde, int pageNumber)
{
  addPage(a, s, addr, qtde, pageNumber);

  if(s->usedPages == qtde){
    page *aux = a->first;
    a->first = a->first->prox;
    free(aux);
  }
}

void freePages(args* a){
  page* p = a->first;
  while(p != NULL){
    a->first = a->first->prox;
    free(p);
    p = a->first;
  }
}