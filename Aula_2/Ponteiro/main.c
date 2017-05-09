#include <stdio.h>

  int main(){
     int x = 25;//Declara a variável x e inicializa com o valor 25
     int* y = &x;//Cria o ponteiro y e y recebe o indereço de x
     *y = 30;//Coloca o valor 30 no endereço que y recebeu

     printf("Valor atual de x: %i\n", x);

     return 0;
  }
