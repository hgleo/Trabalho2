// Permissões vendedor

//     Alocar quantidade de vagas na garagem;
//     Realocar quantidade de vagas;
//     Cadastrar novo carro; <- TÁ FEITO
//     Precisará de algumas informações: preço, modelo, marca, ano, etc. <- QUISER BOTAR MAIS COLOCA
//     Pesquisar veículo <- AJUSTAR O TOUPPER PARA PESQUISAR TUDO EM MAIÚSCULO
//     Remover carro; <- FUNÇÃO QUE LIBERA A MEMÓRIA DE TODOS OS PONTEIROS + O DA STRUCT
//     Checar quantidade de clientes, e seus nomes;
//     Permissões comprador:
//     Comprar carro;
//     Alugar carro;
//     Ir embora (Encerra Programa); <- TÁ FEITO

// O sistema de identificação (vendedor ou comprador), será administrado por base de um banco de 
// dados improvisado, utilizando arquivos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARROS 100

typedef struct {
    char marca[20];
    char modelo[20];
    char placa[7];
    int valor;
    int aluguel;
    int ano;
    int alugado;
} Carro;

Carro **alocar(int quantidade_carros){

    Carro **carros = (Carro **) malloc (quantidade_carros * sizeof(Carro*));
    for(int i=0; i < quantidade_carros; i++){
      carros[i] = (Carro *) malloc (sizeof(Carro));
    }
}

int cadastrar_carro(Carro** carros, int quantidade_carros) {

  if (quantidade_carros == 0)
    *carros = (Carro *) malloc(sizeof(Carro));
  else
    *carros = (Carro *) realloc(*carros, quantidade_carros  * sizeof(Carro));
  
  
  printf("\nDigite a marca do carro: ");
  scanf("%s", carros[quantidade_carros]->marca);
  printf("Informe o modelo do carro: ");
  scanf("%s", carros[quantidade_carros]->modelo);
  printf("Informe a placa do carro: ");
  scanf("%s", carros[quantidade_carros]->placa);
  printf("Informe o ano do carro: ");
  scanf("%d", &carros[quantidade_carros]->ano);
  printf("Informe o valor do carro: ");
  scanf("%d", &carros[quantidade_carros]->valor);
  printf("Informe o valor do aluguel em reais/mes do carro: ");
  scanf("%d", &carros[quantidade_carros]->aluguel);
  carros[quantidade_carros]->alugado = 0;
  quantidade_carros++;
  printf("Carro cadastrado com sucesso!\n");

  return quantidade_carros;
}

void exibir_carros(Carro* carros, int quantidade_carros) {
  if (quantidade_carros == 0 ) {
    printf("Não há carros disponíveis.\n");
    return;
  }

  printf("Carros disponíveis: \n");
  for (int i = 0; i < quantidade_carros; i++) {
    if (!carros[i].alugado) {
      printf("Marca: %s\n", carros[i].marca);
      printf("Modelo: %s\n", carros[i].modelo);
      printf("Placa: %s\n", carros[i].placa);
      printf("Ano: %d\n", carros[i].ano);
      printf("Valor: %d\n", carros[i].valor);
      printf("Aluguel: %d\n",carros[i].aluguel);
      printf("\n");
    }
  }
}

void exibir(Carro* carros, int i) {
  
      printf("Marca: %s\n", carros[i].marca);
      printf("Modelo: %s\n", carros[i].modelo);
      printf("Placa: %s\n", carros[i].placa);
      printf("Ano: %d\n", carros[i].ano);
      printf("Valor: %d\n", carros[i].valor);
      printf("Aluguel: %d\n",carros[i].aluguel);
      printf("\n");
}

void pesquisa_carros(Carro* carros, int tipo){
  char placa[7];
  char modelo[20];
  int ano;

  if(tipo == 1){ // PESQUISA PELA PLACA

      printf("\nDigite a placa do veículo a ser pesquisado: ");
      scanf("%s",placa);

      for(int i=0; i<100;i++){
        if(strcmp(carros[i].placa,placa) == 0) {
          printf("Veículo encontrado!\n");
          exibir(carros, i);
      }
    }
  }
  if(tipo == 2){ // PESQUISA PELO MODELO

      printf("\nDigite o modelo do veículo a ser pesquisado: ");
      scanf("%s",modelo);

      for(int i=0; i<100;i++){
        if(strcmp(carros[i].modelo,modelo) == 0) {
          printf("Veículo encontrado!\n");
          exibir(carros,i);
      }
    }
  }
  if(tipo == 3){ // PESQUISA PELO ANO

      printf("\nDigite o ano do veículo a ser pesquisado: ");
      scanf("%d",&ano);

      for(int i=0; i<100;i++){
        if(carros[i].ano == ano) {
          printf("Veículo encontrado!\n");
          exibir(carros, i);
      }
    }
  }
}

void alugar_carro(Carro* carros, int quantidade_carros) {

  int escolha = 0;
  char modelo[20];

  printf("Informe o modelo do carro que deseja alugar: ");
  scanf("%s", modelo);

  for (int i = 0; i < quantidade_carros; i++) {
    if (!carros[i].alugado && strcmp(carros[i].modelo, modelo) == 0) {
      carros[i].alugado = 1;
      printf("O aluguel deste carro custa %d Reais/mes, deseja prosseguir?\ndigite 1 para sim ou 0 para não\n",carros[i].aluguel);
      scanf("%d",&escolha);
      if(!escolha)
        printf("O carro não foi alugado -retornando ao menu-\n\n");
      else
        printf("O carro foi alugado, parabens -retornando ao menu-\n\n");
      return;
    }
  }

  printf("Não foi possível alugar o carro informado.\n");
}

void apagar_carro(Carro* carros, int quantidade_carros) {
  char modelo[50];
  printf("Informe o modelo do carro que deseja alugar: ");
  scanf("%s", modelo);

  for (int i = 0; i < quantidade_carros; i++) {
    if (strcmp(carros[i].modelo, modelo) == 0) {
      for (int j = i; j < quantidade_carros - 1; j++) {
        carros[j] = carros[j + 1];
      }
      quantidade_carros--;
    }
  carros = (Carro *) realloc(carros, quantidade_carros * sizeof(Carro));
    if (carros == NULL) {
        printf("Não foi possível apagar o carro.\n\n");
        return;
    }
    printf("Carro apagado com sucesso!\n\n");
    return;
    }
}

int main() {
  int opcao = 0, quantidade_carros = 0;
  Carro *carros;
  
  // ATENÇÃO:
  // FALTA AINDA FAZER UMA FORMA DE VOLTAR PARA A ESCOLHA COMPRADOR/VENDEDOR, UMA VEZ QUE ESCOLHIDA NAO TEM VOLTA

  int option;
  int i;
  printf("Voce e um comprador ou um vendedor?\n");
  printf("[1]-> Comprador\n");
  printf("[2]-> Vendedor\n");
  printf("[0]-> Nenhum dos dois, entrei na loja por engano.\n");
  printf("[->] ");
  scanf("%d",&option);

  if(option == 1) {
    do{
    printf("Escolha uma opção: \n");
    printf("[1]-> Exibir carros disponíveis\n");
    printf("[2]-> Alugar carro\n");
    printf("[0]-> Encerrar programa\n");
    printf("[->] ");
    scanf("%d", &opcao);
    switch (opcao) {
      case 1:
        exibir_carros(carros,quantidade_carros);
        break;
      case 2:
        alugar_carro(carros,quantidade_carros);
        break;
      case 0:
        printf("Ok, volte sempre!\n");
        break;
      default:
        printf("Opção inválida.\n");
        break;
    }
  }while (opcao != 0);
  }
  if(option == 2){
    do {
    printf("\nEscolha uma opção: \n");
    printf("[1]-> Cadastrar carro\n");
    printf("[2]-> Exibir carros disponíveis\n");
    printf("[3]-> Pesquisar carros\n");
    printf("[3]-> Apagar carro\n");
    printf("[0]-> Encerrar programa\n");
    printf("[->] ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        quantidade_carros = cadastrar_carro(&carros,quantidade_carros);
        break;
      case 2:
        exibir_carros(carros,quantidade_carros);
        break;
      case 3:
        printf("\nEscolha uma opção de pesquisa: \n");
        printf("[1]-> Pesquisa pela Placa \n");
        printf("[2]-> Pesquisa pelo Modelo\n");
        printf("[3]-> Pesquisa pelo Ano\n");
        printf("[->] ");
        scanf("%d",&i);
        pesquisa_carros(carros,i);
        break;
      case 4:
        apagar_carro(carros,quantidade_carros);
        break;
      case 0:
        printf("Volte ao trabalho!!\n");
        break;
      default:
        printf("Opção inválida.\n");
        break;
    }
  }while (opcao != 0);
  }

  free(carros);
  return 0;
}