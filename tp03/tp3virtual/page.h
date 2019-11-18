#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct page {
    unsigned addr;
    int pageNumber;
    int time;
    struct page* prox;
} page;

void rePage(args* a, stats* s, unsigned addr);

void addPage(args* a, stats* s, unsigned addr, int qtde, int pageNumber);

//Lê conteúdo do arquivo de entrada.
void lerArquivo(args* a, stats* s);