// #include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include "entrada.h"
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// #include <unistd.h>

int main(int argc, char *argv[])
{
  args* a;
  a = malloc(sizeof(args));
  // Verifica se a entrada e valida.
  if (verificaEntrada(argc, argv) != 0)
  {
    return 1;
  }
  printArgs(a);
  // TODO ler arquivo
 	//Lê arquivo de entrada.
  lerArquivo(argv[2]);
  // formato arquivo de entrada
  // endereco de memoria seguido de R ou W
  // 0785db58 W
  // 000652d8 R

  // TODO simular, coletando estatisticas
  free(a);

  return 0;
}
