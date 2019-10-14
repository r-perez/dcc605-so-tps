# Trabalho Prático #2 – Escalonador de Processos

* [Pasta com o arquivo do relatório do TP](https://drive.google.com/drive/folders/1rhiKy7a3qocgxJwshwm3clsBJNfeN3RR)

## 1. Introdução

* **SO: XV6**. Ao longo desse trabalho utilizaremos um sistema operacional simples de aprendizado chamado XV6.
* **Emulador: QEMU**. Para rodá-lo, você irá precisar de
compilar os arquivos fontes e usar o emulador de processador QEMU.
* Dica: [xv6 - disciplina so do mit](http://pdos.csail.mit.edu/6.828/2014/xv6.html)
* Dica: [xv6 - manual](https://pdos.csail.mit.edu/6.828/2018/xv6/xv6-rev11.pdf)

## 2. Obtendo o XV6

`git clone git://github.com/mit-pdos/xv6-public.git`

`sudo apt install qemu`

`cd xv6-public`

`make`

`make qemu`

## 3. Escalonador

Sua primeira tarefa é entender a política atual de escalonamento do XV6. Para isso, LEIA o [capítulo 5 do manual do XV6](https://pdos.csail.mit.edu/6.828/2018/xv6/xv6-rev11.pdf). Em seguida, localize o código do escalonador no código fonte do XV6 e tente entender o seu fluxo de execução. Em seguida, responda as seguintes questões:

### 3.1 Tarefa: Responda sobre escalonamento

* Qual a política de escalonamento é utilizada atualmente no XV6 ?
* Quais processos essa política seleciona para rodar ?
* O que acontece quando um processo retorna de uma tarefa de I/O ?
* O que acontece quando um processo é criado e quando ou quão frequente o escalonamento acontece ?

### 3.2 Tarefa: modificar a política atual do escalonador

Sua primeira tarefa será modificar a política atual do escalonador para que o processo de preempção ocorra a cada intervalo n de tempo (medidos em ticks do clock) ao invés de a cada 1 tick do clock. Adicione a linha seguinte ao arquivo `param.h` e inicialize o valor `INTERV` para 5. Utilize essa constante para estabelecer o intervalo entre preempções.

`#define INTERV 5`

## 4. Escalonamento de Filas Multinível

### 4.1 Tarefa: Criar a chamada de sistema `set_prio`
Para isso, você deverá criar a chamada de sistema `set_prio` que altera a prioridade atual do processo.

`int set_prio(int priority)`

* Dica: para aprender como criar uma chamada de sistema consulte o [tutorial](http://cse.csusb.edu/tongyu/courses/cs660/labs/lab3.php).

### 4.2 Tarefa: implementar uma política de escalonamento de filas multinível

Sua tarefa agorá será modificar o atual escalonador do XV6 para implementar uma política de escalonamento de filas multinível como descrito acima. Posteriormente, você deverá ainda adicionar um mecanismo de aging para evitar inanição. Isto é, processos que estejam muito tempo em uma fila de baixa prioridade podem ser promovidas a fila de prioridade mais alta seguinte. Dessa forma, você deverá criar mais duas constantes de tempo para comparar com a informação do tempo de espera de um processo e verificar se ele deve ser “passado” para uma fila de maior prioridade. Você pode começar com o valor de 5 ticks mas deverá também experimentar outros valores diferentes para as constantes abaixo:

`//Promove um processo da fila 1 para fila 2 se tempo de espera maior que 5 ticks`

`#define 1TO2 5`

`//Promove um processo da fila 2 para fila 3 se tempo de espera maior que 5 ticks`

`#define 2TO3 5`

## 5. Testes - extrair algumas estatísticas de cada processo executado

### 5.1 Tarefa: estender a estrutura proc no arquivo `proc.h`

Para isso você deverá estender a estrutura proc no arquivo `proc.h`. Adicione à estrutura proc os seguintes campos:

`uint ctime; // Tempo quando o processo foi criado`

`int stime; //Tempo SLEEPING`

`int retime; //Tempo READY(RUNNABLE) time`

`int rutime; // Tempo executando (RUNNING)`

### 5.2 Tarefa: Criar a chamada de sistema wait2

Para extrair essas informações de cada processo e apresentá-la para o usuário você também deverá criar outra chamada de sistema. Essa nova chamada de sistema `wait2` deverá estender a chamada de sistema atual `wait`:

`int wait2(int* retime, int* rutime, int* stime)`

### 5.3 Tarefa: Criar um programa `sanity.c`

Você deverá criar um programa chamado `sanity.c` que recebe como argumento um parâmetro inteiro `n`. Esse programa irá criar `3*n` processo com fork e esperar até que cada um deles termine imprimindo as estatísticas da chamada de sistema `wait2` para cada processo terminado.

Cada um dos `3n` processos será de um dos 3 tipos abaixo:

* Processos com (pid mod 3 == 0) serão processos do tipo CPU-Bound: executam 100
vezes um loop vazio de 1000000 iterações.

* Processos com (pid mod 3 == 1) serão processos de tarefas curtas S-CPU: executam
100 vezes um loop vazio de 1000000 iterações e a cada passada das 100 chama a função do
sistema yield.

* Processos com (pid mod 3 == 2) serão processos IO-Bound: para simular chamadas
de IO executa 100 vezes a chamada de sistema sleep(1).

Esse programa deverá ainda imprimir para cada processo terminado:

* O identificado do processo (pid) e o seu tipo {CPU-Bound, S-Bound, IO-Bound}.

* O seu tempo de espera, tempo executando e tempo de IO.

Após todos os 3n processo serem executados imprima:

* Tempo médio no estado SLEEPING para cada tipo de processo.

* Tempo médio READY para tipo de processo.

* Tempo médio para completar para completar (turnaround time) a tarefa para tipo de processo.

### 5.4 Tarefa: verificar se o algoritmo de escalonamento está obedecendo a ordem de prioridades

Para verificar se o algoritmo de escalonamento está obedecendo a ordem de prioridades você poderá ainda criar um programa que cria, por exemplo, 20 processos do tipo CPU-Bound e atribui a cada um deles prioridades diferentes através da chamada de sistema set_prio. Avalie também qual o efeito do aging na ordem de execução dos processo à medida em que as constantes do mesmo são modificadas.
