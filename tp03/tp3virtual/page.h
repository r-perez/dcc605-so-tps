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
