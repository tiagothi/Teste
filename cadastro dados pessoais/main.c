#include <stdio.h>
#include <stdlib.h>

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
1630482021017
Maria Eduarda da Concei��o Santos
RA:*
 ****************/


int main()
{
   struct dados{


   char Nome[31], Sobrenome[31];
   char Rua1[71], Rua2[71];
   char Bairro1[71], Bairro2[71];
   int Ncasa;
   char Nascimento[31];
   int CEP;
   char Email[81];
   };
   int i =0;
   /**Declara variavies do tipo ponteiros e struct*/

struct dados std1,*ptr_std1;

ptr_std1=&std1; /**Encontra endere�o da variavel**/

printf("\n ______|Cadastro de Pessoas|______\n");

do
{

system ("cls");

     printf(" Nome completo: \n");
     scanf("%s %s", &ptr_std1->Nome, &ptr_std1->Sobrenome);

     printf(" \nData de Nascimento: \n");
     scanf("%s",&ptr_std1->Nascimento);

     printf(" \nNome da Rua: \n");
     scanf("%s %s",&ptr_std1->Rua1, &ptr_std1->Rua2);

     printf(" \nNumero da casa: \n");
     scanf("%d",&ptr_std1->Ncasa);

     printf(" \nNome do Bairro: \n");
     scanf("%s %s",&ptr_std1->Bairro1, &ptr_std1->Bairro2);

     printf(" \nCEP da rua: \n");
     scanf("%d", &ptr_std1->CEP);

     printf("\nInforme Email: \n");
     scanf("%s", &ptr_std1->Email);

   printf("\n___________________\n");



   printf("\n Nome completo = %s %s", ptr_std1->Nome, ptr_std1->Sobrenome);
   printf("\n Data de Nascimento = %s", ptr_std1->Nascimento);
   printf("\n Endereco = %s %s", ptr_std1->Rua1, ptr_std1->Rua2);
   printf("\n Bairro = %s %s", ptr_std1->Bairro1,ptr_std1->Bairro2);
   printf("\n Numero da casa = %d", ptr_std1->Ncasa);
   printf("\n CEP da rua = %d", ptr_std1->CEP);
   printf("\n Email = %s", ptr_std1->Email);

   printf("\n\n____|Cadastro Realizado com sucesso|____\n\\n");

printf("\npara continuar digite qualquer valor\n");

printf("\nPara encerrar digite 1\n");
scanf("%d", &i);
if(i ==1)
   break;
}while(i != 1);


    return 0;
}