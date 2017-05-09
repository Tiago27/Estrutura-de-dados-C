#include <stdio.h>
#include <malloc.h>
#define MAX 50

typedef int TIPOCHAVE;//Cria um tipo abstrato

typedef struct{
  TIPOCHAVE chave;
  //outros campos...
}REGISTRO;

typedef struct{
  REGISTRO A[MAX+1];
  int numeroDeElementos;
}LISTA;

//1-Inicializar Lista
void inicializarLista(LISTA* l){
  l->numeroDeElementos=0;
  //printf("Valor de l: %p\n", l);//verificar indereço da lista l
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
//4.1-Busca por elemento sentinela
int buscaSentinela(LISTA* l, TIPOCHAVE ch){
  int i=0;

  l->A[l->numeroDeElementos].chave=ch;

  while(l->A[i].chave != ch)
    i++;
  if(l->numeroDeElementos==i)
    return -1;
  else
    return 1;
}
//4.3-Busca Binaria
int buscaBinaria(LISTA* l, TIPOCHAVE ch){
    int esq, dir, meio;
    esq=0;
    dir=l->numeroDeElementos-1;
    while(esq <= dir){
        meio=((esq+dir)/2);
        if(l->A[meio].chave == ch)
            return meio;
        else{
            if(l->A[meio].chave < ch)
                esq=meio+1;
            else
                dir=meio-1;
        }
    }
     return -1;
}

//5-Inserção de elemento na lista ordenada
//Criar tipo boolean
//Criando enumeração
enum boolean{
   true=1, false=0
};
//permitindo a sua declaração como um tipo qualquer
typedef enum boolean bool;
bool inserirElementoNaListaOrdenada(LISTA* l, REGISTRO reg){
  if(l->numeroDeElementos>=MAX)
    return false;
  int pos=l->numeroDeElementos;
  while(pos > 0 && l->A[pos-1].chave > reg.chave){
    l->A[pos] = l->A[pos-1];
    pos--;
  }
  l->A[pos]=reg;
  l->numeroDeElementos++;
}
//6-Excluir elemento da lista
bool excluirElementoDaLista(TIPOCHAVE ch, LISTA* l){
  int pos, i=1, j;
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
    LISTA* lista1 = (LISTA*) malloc(sizeof(LISTA));
    //inicializar lista
    inicializarLista(lista1);

    //Passando valores para a lista
    REGISTRO A, B, C, D;//Criar variavel registro
    A.chave = 12;//Atribuir valores aos campos do registro A
    B.chave = 13;
    C.chave = 11;

    inserirElementoNaListaOrdenada(lista1, A);//Passando Variavel do tipo LISTA e variavel  do tipo REGISTRO como parametros
    inserirElementoNaListaOrdenada(lista1, B);
    inserirElementoNaListaOrdenada(lista1, C);
    D.chave = 17;
    exibirLista(lista1);
    inserirElementoNaListaOrdenada(lista1, D);
    exibirLista(lista1);

    excluirElementoDaLista( 11,lista1);

    exibirLista(lista1);
    int result = buscaSequencial(lista1, 12);
    if(result==-1)
        printf("A chave nao foi incontrada");
    else
        printf("A chave %d foi incontrada", lista1->A[result].chave);

    printf("\nTamanho da lista: %d\n", tamanho(lista1));
    reinicializarLista(lista1);
    exibirLista(lista1);
    printf("\nTamanho da lista: %d\n", tamanho(lista1));
    //printf("Valor de lista1 lista: %p\n", lista1->A);//verificar endereço da lista1
    return 0;
}
