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

  // TODO ler arquivo
  // formato arquivo de entrada
  // endereco de memoria seguido de R ou W
  // 0785db58 W
  // 000652d8 R
  
  // TODO simular, coletando estatisticas
  
  return 0;
}
