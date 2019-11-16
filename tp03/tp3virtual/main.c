#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include "entrada.h"
#include "stats.h"
#include "page.h"
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// #include <unistd.h>

// Valgrind
// valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./tp3virtual lru log/teste1.log 4 128
// Valgrind verbose: muita informacao
// valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./tp3virtual lru log/teste1.log 4 128
int main(int argc, char *argv[])
{
  // inicializacao de variaveis
  args* a;
  a = malloc(sizeof(args));
  stats* s;
  s = malloc(sizeof(stats));
  setStats(s, 0, 0);

  if (setEntrada(argc, argv, a) != 0){
    return 1;
  }

  //Page table. Memória Física.
  //Duvida
  //Nao sei se é assim msm q tem q declarar essas tabelas.
  //Na especificação fala sobre uma estrutura de quadros fisicos, mas eu nao faço ideia de como fazer.
  //Tbm n sei se tem q usar TLB ou se só uma tabela de paginas resolve.
  int page[a->tamPagina*1024];
  int fisica[a->tamTotal*1024];
  for(int i = 0; i < a->tamPagina*1024; i++)
    page[i] = -1;
  for(int i = 0; i < a->tamTotal*1024; i++)
    fisica[i] = -1;

  //Duvida
  //Pagina em formato de struct. Acho q nao vai ser necessario.
  //Talvez seja necessario fazer algo assim na repesentação dos quadros fisicos (ta escrito na especificação)
  /* pgt* page[a->tamPagina];
  for(int i = 0; i < a->tamPagina; i++){
    printf("a\n");
    page[i] = malloc(sizeof(pgt));
  } */

  //Lê arquivo de entrada.
  lerArquivo(a, page, fisica);

  // TODO simular, coletando estatisticas
  printf("%s\n", "Executando o simulador...");
  printArgs(a);
  printStats(s);

  //Printa s só pra conferir o valor
  printf("s: %d", a->s);
  endl();

  free(a);
  free(s);
  return 0;
}
