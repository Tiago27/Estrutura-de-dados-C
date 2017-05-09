#include <stdio.h>
#include <malloc.h>

int main(){
   int* y=(int*) malloc(sizeof(int));
   //malloc aloca(reserva) memória para um tipo inteito
   //O type cast (int*) diz que a memória reservada é um ponteiro para inteiro
   //int* y recebe o indereço da memória que foi alocada pelo malloc
   *y = 20;//A memória reservada pelo malloc recebe o valor 20
   int z = sizeof(int);
   printf("*y=%i z=%i\n", *y, z);
}
