#include <stdio.h>
#define alturaMaxima 225

typedef struct{
  int peso;//CAMPO peso em quilogramas
  int altura;//CAMPO altura em centimetroa
} PesoAltura;

int main(){
    PesoAltura pessoa1;
      pessoa1.peso=80;
      pessoa1.altura=185;

    printf("Peso: %i, Altura: %i. \n", pessoa1.peso, pessoa1.altura);

    if(pessoa1.altura>alturaMaxima)
        printf("Pessoa acima da alutura Maxima!");
    else
        printf("Pessoa abaixo da altura Maxima!");
    return 0;
}
