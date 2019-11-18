#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct page {
    unsigned addr;
    int pageNumber;
    int time;
    struct page* prox;
} page;

void addPage(args* a, stats* s, unsigned addr, int qtde, int pageNumber);

void changePage(args* a, stats* s, unsigned addr);

bool readPage(args* a, unsigned addr);

//Lê conteúdo do arquivo de entrada.
void lerArquivo(args* a, stats* s);