#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entrada.h"
#include "stats.h"

/*
  Lê conteúdo do arquivo de entrada.
*/
void lerArquivo(args* a, int* page, int* fisica)
{
  unsigned addr;
  char rw;
  int pageNumber = 0;
  FILE* file;

  file = fopen(a->arquivo, "r");

  if(file == NULL){
    printf("%s\n", "Erro: Falha na abertura do arquivo");
    exit(1);
  }

  //Lê as linhas do arquivo enquanto houverem linhas.
  while(fscanf(file, "%x %c", &addr, &rw) == 2)
  {
    //Duvida
    //Esse é o método escrito na especificação pra descobrir a pagina correspondente à uma endereço.
    //Porém, creio q esse nao seja o indice da pagina direto na tabela de paginas, pq os números são mto grandes.
    //Se vc da page[pageNumber] quase sempre da Seg Fault.
    //Pode ser q tenha um jeito de descobrir o indice mas eu n faço ideia de como é.
    pageNumber = addr >> a->s;

    //Checa tabela de paginas
    /* if(page[pageNumber] == -1){

    } */

    printf("%x %c", addr, rw);
    endl();
    printf("Página: %d", pageNumber);
    endl();
    //printf("%d\n", page[pageNumber]);
  }

  fclose(file);
}