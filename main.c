#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX 100




int cont;
struct cadastro{
    int lan,cor,ficha,quanti,cod_prod;
    char nome[30];

};
struct cadastro cad[MAX];
int quantp = 0;

void cadprod(struct cadastro produto){
    cad[quantp] = produto;
    quantp++;
}
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
  printf("\nVoltando para o menu principal..");
  sleep(5);
  system("cls");
  main();
}
void erro(){
  printf("ops,voce encontrou um erro!");
  printf("\nPor favor relatar o TI");
  sleep(500);

  main();


}





void ajuda(){
  printf("Entao voce eh um novo usuario?");

  printf("\n Vamos para um guia rapido de como cadastrar um produto");

  printf("\n\t\t Para cadastrar um produto sao necesserias algumas informacoes:");
  printf("\n\t\t 1 - Nome ");
  printf("\n\t\t 2 - Lancamento ");
  printf("\n\t\t 3 - Cor (em numerais)");
  printf("\n\t\t 4 - Ficha ");
  printf("\n Com esses quatro simples identificadores voce podera realizar as seguintes operacoes: ");
  printf("\n\t\t Cadastra um novo produto ");
  printf("\n\t\t Buscar um produto ja cadastrado ");
  printf("\n\t\t Excluir um produto ja cadastrado ");
  printf("\n\n");

  printf("Fique atento para novas atualizacoes!");

  printf("Deseja retornar ao menu principal? 1- Sim 2- Nao");
  scanf("%d",&volta);
  if(volta == 1){
    main();

  }else{
    exit(EXIT_SUCCESS);
  }

}

void cadastro (){
    printf("Bem vindo ao menu de cadastro do produto ");
    char op,qp[10];
    int i,j,c;
    do{
        op='n';
        fflush(stdin);
        printf("\nInforme o nome do produto: ");
        scanf("%s",cad[quantp].nome);


        fflush(stdin);
        printf("\nQuantidade de produtos: ");
        scanf("%d",&qp);




        printf("\nInforme o lancamento do produto: ");
        scanf("%d",&cad[quantp].lan);
        printf("\nInforme a cor do produto: ");
        scanf("%d",&cad[quantp].cor);
        printf("\nInforme a ficha do produto: ");
        scanf("%d",&cad[quantp].ficha);
        cad[quantp].cod_prod = 1+rand()%100;
        printf("\nO codigo do seu produto eh %d",cad[quantp].cod_prod);
        quantp++;

        printf("\nDeseja continuar? [s] - sim [n] - nao");
        scanf("%d",&op);


    }while(op == 's');
    sucesso();
}
void busca(){
  printf("Voce esta no menu de busca");
  int i, x;
  char nome[25];
    do{
            printf("MENU DE BUSCA\n");
            printf("1- Mostrar lista de produtos\n");
            printf("2- Buscar pelo nome produto\n");;
            printf("3- Sair do menu busca\n");
            printf("Digite o numero da opcao desejada \n");
            scanf("%d",&x);
            system("cls");
            switch(x){
            case 1:
                printf("Lista de Produtos ");
                for(i=0;i<quantp;i++){
                        printf("\nProduto %d\n",i+1);
                        printf("==============\n");
                        printf("Codigo do produto:......%d\n",cad[i].cod_prod);
                        printf("Nome do produto:........%s\n ",cad[i].nome);
                        printf("Lancamento do produto:..%d\n",cad[i].lan);
                        printf("Cor do produto:.......%d\n",cad[i].cor);
                        printf("Ficha do produto:.......%d\n",cad[i].ficha);
                        printf("==============\n");

                }break;
            case 2:
                printf("Digite o nome do produto que deseja procurar: \n");
                scanf("%s",&nome);
                for(i = 0;i<quantp;i++){
                    if(strcmp (nome, cad[i].nome) == 0){

                        printf("==============\n");
                        printf("Codigo do produto:.......%d\n",cad[i].cod_prod);
                        printf("Nome do produto:........%s\n ",cad[i].nome);
                        printf("Lancamento do produto:..%d\n",cad[i].lan);
                        printf("Cor do produto:.......%d\n",cad[i].cor);
                        printf("Ficha do produto:.......%d\n",cad[i].ficha);
                        printf("==============\n");


                       }
                }break;
            case 3:
                main();
                break;


            }
    }while(x!=3);
    system("cls");


}



void exclui(){
    int i,j,c;
    int cod_b,op;

    printf("Voce esta no menu de exclusao\n");



    printf("Informe o codigo do produto que deseja excluir ");
    scanf("%d",&cod_b);
    for(i = 0;i<quantp;i++){
        if(cad[i].cod_prod == cod_b){
                for(j=i;j<quantp;j++){
                    cad[j] = cad[j+1];
                }
                quantp--;
                c++;
                break;
            }
        }if(c>0){
            printf("\nProduto excluido!!");
            main();

        }else{
            printf("Esse numero de codigo nao existe\n");

        }
    }




int main(){
  int input;
 


  system("cls");
  printf("Ola, bem vindo ao ScP");


  printf ("\n\t\t\t=================================\n");
  printf("\t\t\t 1- Cadastro de produtos");
  printf("\n\t\t\t 2 - busca e exibicao ");
  printf("\n\t\t\t 3 - remocao");
  printf("\n\t\t\t 4 - Ajuda");
  printf("\n\t\t\t 5 - Sair");
  printf ("\n\t\t\t=================================\n");

  printf("\npor favor, insira a opcao desejada ");
  fflush(stdin);
  scanf("%d",&input);

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

    return 0;
}













