#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entrada.h"
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// #include <unistd.h>

int main(int argc, char *argv[])
{
  // Verifica se a entrada e valida.
  if (verificaEntrada(argc, argv) != 0)
  {
    return 1;
  }

  //Lê arquivo de entrada.
  lerArquivo(argv[2]);

  // TODO simular, coletando estatisticas

  return 0;
}
