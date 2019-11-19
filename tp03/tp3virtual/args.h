#include "page.h"
#include "stats.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct argumentos
{
  char* algoritmo;
  char* arquivo;
  int tamPagina;
  int tamTotal;
  int modoDebug;
  unsigned s;
  page* first;
  page* last;
};

typedef struct argumentos args;

void setArgs(args* a, char* algoritmo, char* arquivo, int tamPagina, int tamTotal, int modoDebug);

void printArgs(args* a);

//Lê conteúdo do arquivo de entrada.
void lerArquivo(args* a, stats* s);

//Adiciona nova pagina
void addPage(args* a, stats* s, unsigned addr, int qtde, int pageNumber);

//Aplica politicas de substituição
void changePage(args* a, stats* s, unsigned addr, int qtde, int pageNumber);

//Realiza leitura de endereços
bool readPage(args* a, unsigned addr);

//Aplica politicas temporais
void temporal(args* a, stats*s, unsigned addr, int qtde, int pageNumber);

//Aplica politica randomica
void randomP(args* a, stats* s, unsigned addr, int pageNumber);

//Desaloca paginas
void freePages(args* a);

//Modo debug.
//1 = imprime leitura e escrita, 2 = imprime apenas leitura, 3 = imprime apenas escrita
void printDebug(args* a, unsigned addr, char rw);
