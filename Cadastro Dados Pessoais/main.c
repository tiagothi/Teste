#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/****************
 * Programa que cadastra dados  pessoais *
 ****************/

/****************
  Integrantes do grupo
Gustavo Apparecido
RA: 1630482021015
Paulo Barchielli
RA: 1630482021026
Jonas pichelli Madoenho
RA: 1630482021034
Tiago Durante
RA: 1630482021017
Maria Eduarda da Conceição Santos
RA:*
 ****************/

    int main()

   {
   struct dados
   {


   char Nome[31], Sobrenome[31];
   char Rua1[71], Rua2[71];
   char Bairro1[71], Bairro2[71];
   int Ncasa;
   char Nascimento[31];
   int CEP;
   char Email[81];
   };

   int i =0;

   //Declara variavies do tipo ponteiros e struct

    struct dados std1,*ptr_std1;

    ptr_std1=&std1; //Encontra endereço da variavel



    do
    {

    system ("cls");

    printf("***Cadastro de dados pessoais***\n\n");


     printf("Nome completo: ");
     scanf("%s %s", &ptr_std1->Nome, &ptr_std1->Sobrenome);

     printf("Data de Nascimento: ");
     scanf("%s",&ptr_std1->Nascimento);

     printf("Nome da Rua: ");
     scanf("%s %s",&ptr_std1->Rua1, &ptr_std1->Rua2);

     printf("Numero da casa: ");
     scanf("%d",&ptr_std1->Ncasa);

     printf("Nome do Bairro: ");
     scanf("%s %s",&ptr_std1->Bairro1, &ptr_std1->Bairro2);

     printf("CEP da rua: ");
     scanf("%d", &ptr_std1->CEP);

     printf("Informe Email: ");
     scanf("%s", &ptr_std1->Email);

     printf("\n________________________________________________\n");



    printf("\n Nome completo = %s %s", ptr_std1->Nome, ptr_std1->Sobrenome);
    printf("\n Data de Nascimento = %s", ptr_std1->Nascimento);
    printf("\n Endereco = %s %s", ptr_std1->Rua1, ptr_std1->Rua2);
    printf("\n Bairro = %s %s", ptr_std1->Bairro1,ptr_std1->Bairro2);
    printf("\n Numero da casa = %d", ptr_std1->Ncasa);
    printf("\n CEP da rua = %d", ptr_std1->CEP);
    printf("\n Email = %s", ptr_std1->Email);

    printf("\n\n****Cadastro Realizado com sucesso!****\n\n");

    printf("\n A - Para continuar digite qualquer valor.\n");

    printf("\n B - Para encerrar digite [1].\n");
    scanf("%d", &i);

    if(i ==1)

    break;
    }while(i != 1);


        return 0;
    }
