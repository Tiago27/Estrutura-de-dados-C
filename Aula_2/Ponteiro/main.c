#include <stdio.h>

  int main(){
     int x = 25;//Declara a vari�vel x e inicializa com o valor 25
     int* y = &x;//Cria o ponteiro y e y recebe o indere�o de x
     *y = 30;//Coloca o valor 30 no endere�o que y recebeu

     printf("Valor atual de x: %i\n", x);

     return 0;
  }
