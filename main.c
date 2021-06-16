#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* teste para ver com qual ele dá menos erro, se é com ou sem esse .h #include "projetoc.h"*/



struct Lista_Produto{
    int lan;
    char cor[10];
    int ficha; 
    int *l, *c, *f;//respectivo a cada um deles

};

struct cad_prod{
  char nome_prod[50];
  int ficha;

  struct Lista_Produto lp;
};
struct cad_prod cp;

void menu_principal();
void sucesso();
void erro();
void cadastro();
void busca();
void exclui();
void ajuda();

//declaração de variaveis 


int input,volta;
//declaração de metodos
void sucesso(){
  system("cls");
  printf("Operacao realizada com sucesso! ");
  //jogar um timer aqui
  printf("Voltando para o menu principal..");
  sleep(500);
  system("cls");
  menu_principal();
}
void erro(){
  printf("ops,voce encontrou um erro!");
  printf("\nPor favor relatar o TI");
  sleep(500);
  system("cls");
  menu_principal();

}

void menu_principal(){
  //colocar um efeito de loading
  printf("Ola, bem vindo ao CaP");

  
  printf ("\t\t\t===============================\n");
  printf("\t\t\t 1- Cadastro de produtos");
  printf("\n\t\t\t 2 - busca e exibicao ");
  printf("\n\t\t\t 3 - remocao");
  printf("\n\t\t\t 4 - Ajuda");
  printf("\n\t\t\t 5 - Sair");
  printf ("\t\t\t===============================\n");

  printf("\npor favor, insira a opcao desejada ");
  fflush(stdin);
  scanf("%d",&input);
  system("cls");
  switch(input){
    case 1:
        cadastro();
    
    break;


    case 2:
        busca();
    
    break;


    case 3:
      exclui();
    
    break;

    case 4:
      ajuda();
    
    
    
    break;
    case 5:
      exit(EXIT_SUCCESS);
    
    default:
    printf("\n\t\t Opcao invalida! \n\n");
    fflush(stdin);


  }

}

void ajuda(){
  printf("Entao voce eh um novo usuario?");

  printf("\n Vamos para um guia rapido de como cadastrar um produto");

  printf("\n\t\t Para cadastrar um produto eh necesserio 3 informacoes:");
  printf("\n\t\t 1 - Lancamento ");
  printf("\n\t\t 2 - Cor ");
  printf("\n\t\t 3 - Ficha ");

  printf("\n Com esses tres simples identificadores voce podera realizar as seguintes operacoes: ");
  printf("\n\t\t Cadastra um novo produto ");
  printf("\n\t\t Buscar um produto ja cadastrado ");
  printf("\n\t\t Excluir um produto ja cadastrado ");
  printf("\n\n");

  printf("Fique atento para novas atualizacoes!");

  printf("Deseja retornar ao menu principal? 1- Sim 2- Nao");
  scanf("%d",&volta);
  if(volta == 1){
    menu_principal();

  }else{
    exit(EXIT_SUCCESS);
  }
  
}

























int main(void) {
  
  menu_principal();
  return 0;
}