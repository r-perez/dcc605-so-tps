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
  setStats(s);

  if (setEntrada(argc, argv, a) != 0)
  {
    return 1;
  }

  printf("%s\n", "Executando o simulador...");

  //Lê arquivo de entrada.
  lerArquivo(a, s);

  printArgs(a);
  printStats(s);

  free(a);
  free(s);
  return 0;
}
