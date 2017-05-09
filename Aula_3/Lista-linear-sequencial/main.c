#include <stdio.h>
#define MAX 50

typedef int TIPOCHAVE;//Cria um tipo abstrato

typedef struct{
  TIPOCHAVE chave;
  //outros campos...
}REGISTRO;

typedef struct{
  REGISTRO A[MAX];
  int numeroDeElementos;
}LISTA;

//1-Inicializar Lista
void inicializarLista(LISTA* l){
  l->numeroDeElementos=0;
}

//2-Retornar número de elemesntos
int tamanho(LISTA* l){
  return l->numeroDeElementos;
}

//3-Exibição/Impressão de listas
void exibirLista(LISTA* l){
  int i;
  printf("Lista: \" ");
  for(i=0; i < l->numeroDeElementos; i++)
    printf("%i ", l->A[i].chave);
  printf(" \" \n");
}
//4-Busca sequencial
int buscaSequencial(LISTA* l, TIPOCHAVE ch){
int i=0;
    while(i < l->numeroDeElementos){
      if(ch == l->A[i].chave)
        return i;//retorna o indice do vetor se encontrado
       else
        i++;
    }
    return -1;//retorna -1 caso não encontre o valor
}

//5-Inserção de um  em posição específica
//Criar tipo boolean
//Criando enumeração
enum boolean{
   true=1, false=0
};
//permitindo a sua declaração como um tipo qualquer
typedef enum boolean bool;
bool inserirElementoNaLista(LISTA* l, REGISTRO reg, int i){
  int j;
  if((l->numeroDeElementos==MAX)||(i<0)||(i>l->numeroDeElementos))
    return false;
  for(j= l->numeroDeElementos; j>i; j--)
    l->A[i]=l->A[j-1];
  l->A[i]=reg;
  l->numeroDeElementos++;
  return true;
}
//6-Excluir elemento da lista
bool excluirElementoDaLista(TIPOCHAVE ch, LISTA* l){
  int pos, j;
  pos = buscaSequencial(l,ch);
  if(pos ==-1)
    return false;
  for(j=pos; j<l->numeroDeElementos-1; j++)
    l->A[j]=l->A[j+i];
  l->numeroDeElementos--;
  return true;
}
//7-Reinicialização de lista
void reinicializarLista(LISTA* l){
  l->numeroDeElementos=0;
}
int main(){

}
