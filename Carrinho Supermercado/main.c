#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************
 * Carrinho de Supermercado *
 ****************/

/****************
 * Integrantes do grupo
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

   typedef
    struct Produto
    {
      int codigo;
      char* descricao;
      float precounit;
    }

    Produto;

    Produto* inicializarProduto()

    {
      Produto *p = (Produto*) malloc(sizeof(Produto));
      p->codigo = 0;
      p->descricao = (char*) calloc(50, sizeof(char));
      p->precounit = 0.0f;

      return p;
    }


    // produtos da loja(escopo global)

    Produto *produtos_da_loja[1000];
    int index_estoque = 0;


    typedef
    struct Carrinho {
      int numitem;
      int qtd;
      float precototal;
      Produto *produto[100];
    } Carrinho;

    Carrinho* inicializarCarrinho() {
      Carrinho *c = (Carrinho*) malloc(sizeof(Carrinho));
      c->numitem    =    0;
      c->qtd        =    0;
      c->precototal = 0.0f;

      // ate' 100 produtos
      for(int i = 0; i < 100; i++)

        {
        c->produto[i] = inicializarProduto();
        }

      return c;
    }

    // fazer copia dos valores de um endereco
    Produto* pegarProduto(int i, int qtd) {
      Produto *resp = inicializarProduto();
      if(i < index_estoque && i >= 0) {
        int codigo      =    produtos_da_loja[i]->codigo;

        float precounit = produtos_da_loja[i]->precounit;

        resp->codigo    =        codigo;
        resp->precounit = qtd*precounit;

        int j = 0;

        if(qtd != 1) {

          int length = snprintf( NULL, 0, "%d", qtd );
          char* snum = (char*) calloc(6, sizeof(char));
          snprintf( snum, length + 1, "%d", qtd );

          for(int k = 0; snum[k] != '\0'; k++) {
            resp->descricao[j++] =    snum[k];
          }

          resp->descricao[j++] =       'x';
          free(snum);
        }
        // copiar valor da descricao
        for(int k = 0; produtos_da_loja[i]->descricao[k] != '\0'; j++, k++) {
          resp->descricao[j] = produtos_da_loja[i]->descricao[k];
        }

      } else {
        printf("ERRO: PRODUTO INEXISTENTE");
      }

      return resp;
    }


    void adicionarProdutosNoCarrinho(Carrinho **c, char* descricao, int qtd) {
      if((*c)->numitem >= 100) {
        printf("ERRO AO ADICIONAR PRODUTO AO CARRINHO: Carrinho cheio");
      } else if(qtd <= 0){
        printf("ERRO AO ADICIONAR PRODUTO AO CARRINHO: Quantidade mal especificada");
      } else {
        int i = 0;
        for(; i < index_estoque; i++) {
          if(strcmp(descricao, produtos_da_loja[i]->descricao) == 0) {
            // colocar produto no carrinho
            (*c)->produto[(*c)->numitem++] = pegarProduto(i, qtd);
            // aumentar precototal
            (*c)->precototal += qtd*produtos_da_loja[i]->precounit;
            // sentinela para atestar ter encontrado produto
            i = index_estoque+1;
          }
        }

        if(i == index_estoque) {
          printf("ERRO AO ADICIONAR PRODUTO: Produto nao encontrado na loja");
        }
      }
    }

    void adicionarProdutoNaLoja(char* descricao, float preco) {
      if(index_estoque >= 10) {
        printf("ERRO AO ADICIONAR PRODUTO A LOJA: estoque cheio");
      } else {
        produtos_da_loja[index_estoque] = inicializarProduto();
        produtos_da_loja[index_estoque]->descricao =      descricao;
        produtos_da_loja[index_estoque]->precounit =          preco;
        produtos_da_loja[index_estoque]->codigo    =  index_estoque;
        index_estoque++;
      }
    }

    void mostrarCarrinho(Carrinho **c) {
      printf("\n==================COMPRAS=====================\n");
      printf("\n|codigo\t\t|\tdescricao\t\t|preco\n");
      printf("----------------------------------------------");
      for(int i = 0; i < (*c)->numitem; i++) {
        printf("\n|%04d\t\t|%15s\t\t|R$%.2f",
        (*c)->produto[i]->codigo, (*c)->produto[i]->descricao, (*c)->produto[i]->precounit);
      }
      printf("\n==============================================");
      printf("\nTOTAL: \t\t\t\t\t\t\t\t R$%.2f\n", (*c)->precototal);
    }

    void adicionarProdutosNaLoja(char* descricoes[], float precos[], int quant) {
      int i = 0;
      for(; i<quant ; i++) {
        adicionarProdutoNaLoja(descricoes[i], precos[i]);
      }
    }

    void mostrarProdutosDaLoja() {
      for(int i = 0; i < index_estoque; i++) {
        printf("%04d\t%15s\t%03.2f\n", produtos_da_loja[i]->codigo, produtos_da_loja[i]->descricao, produtos_da_loja[i]->precounit);
      }
    }

    void Menu(Carrinho **c) {
      int entrada = 0;
      printf("\n\tMENU DA LOJA\n");
      do {
        char *descricao = (char*) calloc(50, sizeof(char));
        int quantidade;
        printf("\nADICIONAR PRODUTO NO CARRINHO[1]\nMOSTRAR PRODUTOS DA LOJA[2]\nMOSTRAR CARRINHO[3]\nFINALIZAR[0]\n\n\t>");
        scanf("%d", &entrada);

        switch (entrada) {
          case 0:
            printf("\nFIM MENU \n");
            break;
          case 1:
            printf("\nNome do produto:\n");
            setbuf(stdin, NULL); // evitar sujeira do scanf
            scanf("%s", descricao);

            printf("\nquantidade:\n");
            setbuf(stdin, NULL); // evitar sujeira do scanf
            scanf("%d", &quantidade);

            adicionarProdutosNoCarrinho(c, descricao, quantidade);
            free(descricao); // evitar transbordamento de memoria
            break;
          case 2:
            mostrarProdutosDaLoja();
            break;
          case 3:
            mostrarCarrinho(c);
            break;
          default:
            printf("ERROR: OPCAO INVALIDA!\n");
        }
      }while(entrada != 0);
    }

    int main(void) {
      //produtos da loja
      //quantidade de produtos(teste)
      int quant = 8;
      //inserindo produtos manualmente
      char* descricoes[] = {"Arroz", "Coca", "Feijao", "Cerveja", "Chocolate", "Biscoito", "Pao", "Limao"};
      //inserir os precos no mesmo index dos produtos
      float precos[] = {12.50, 6.00, 14.20, 20.50, 4.50, 6.20, 5.40, 7.30};
      adicionarProdutosNaLoja(descricoes, precos, quant);

      // Carrinho de compras
      Carrinho *c = inicializarCarrinho();
      // menu de compras
      Menu(&c);

      return 0;
    }
