#include <stdio.h>
#include <malloc.h>

int main(){
   int* y=(int*) malloc(sizeof(int));
   //malloc aloca(reserva) mem�ria para um tipo inteito
   //O type cast (int*) diz que a mem�ria reservada � um ponteiro para inteiro
   //int* y recebe o indere�o da mem�ria que foi alocada pelo malloc
   *y = 20;//A mem�ria reservada pelo malloc recebe o valor 20
   int z = sizeof(int);
   printf("*y=%i z=%i\n", *y, z);
}
