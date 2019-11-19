#include "entrada.h"

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
