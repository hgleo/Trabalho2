#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARROS 100

typedef struct {
  char modelo[20];
  char placa[7];
  int valor;
  int aluguel;
  int ano;
  int alugado;
} Carro;

int quantidade_carros = 0;
Carro *carros;

void cadastrar_carro() {
  carros = (Carro *) realloc(carros, (quantidade_carros + 1) * sizeof(Carro));
  if (carros == NULL) {
    printf("Não foi possível alocar memória para o novo carro.\n");
    return;
  }

  printf("Informe o modelo do carro: ");
  scanf("%s", carros[quantidade_carros].modelo);
  printf("Informe a placa do carro: ");
  scanf("%s", carros[quantidade_carros].placa);
  printf("Informe o ano do carro: ");
  scanf("%d", &carros[quantidade_carros].ano);
  printf("Informe o valor total do carro: ");
  scanf("%d", &carros[quantidade_carros].valor);
  printf("Informe o valor do aluguel/mes: ");
  scanf("%d",&carros[quantidade_carros].aluguel);
  carros[quantidade_carros].alugado = 0;
  quantidade_carros++;
  printf("Carro cadastrado com sucesso!\n");
}

void exibir_carros() {
  if (quantidade_carros == 0 ) {
    printf("Não há carros disponíveis.\n");
    return;
  }

  printf("Carros disponíveis: \n");
  for (int i = 0; i < quantidade_carros; i++) {
    if (!carros[i].alugado) {
      printf("Modelo: %s\n", carros[i].modelo);
      printf("Placa: %s\n", carros[i].placa);
      printf("\n");
    }
  }
}

void alugar_carro() {
  int escolha = 0;
  char modelo[50];
  printf("Informe o modelo do carro que deseja alugar: ");
  scanf("%s", modelo);

  for (int i = 0; i < quantidade_carros; i++) {
    if (!carros[i].alugado && strcmp(carros[i].modelo, modelo) == 0) {
      carros[i].alugado = 1;
      printf("O aluguel deste carro custa %d Reais/mes, deseja prosseguir?\ndigite 1 para sim ou 0 para não\n",carros[i].aluguel);
      scanf("%d",&escolha);
      if(!escolha)
        printf("O carro não foi alugado, retornando ao menu\n");
      else
        printf("O carro foi alugado, parabens\n");
      return;
    }
  }

  printf("Não foi possível alugar o carro informado.\n");
}

void apagar_carro() {
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
        printf("Não foi possível apagar o carro.\n");
        return;
    }
    printf("Carro apagado com sucesso!\n");
    return;
    }
}

int main() {
  int opcao = 0;
  carros = (Carro *) malloc(MAX_CARROS * sizeof(Carro));
  if (carros == NULL) {
    printf("Não foi possível alocar memória para os carros.\n");
    return 1;
  }

  while (opcao != 5) {
    printf("Escolha uma opção: \n");
    printf("[1]-> Cadastrar carro\n");
    printf("[2]-> Exibir carros disponíveis\n");
    printf("[3]-> Alugar carro\n");
    printf("[4]-> Apagar carro\n");
    printf("[5]-> Encerrar programa\n");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        cadastrar_carro();
        break;
      case 2:
        exibir_carros();
        break;
      case 3:
        alugar_carro();
        break;
      case 4:
        apagar_carro();
        break;
      case 5:
        break;
      default:
        printf("Opção inválida.\n");
        break;
    }
  }

  free(carros);
  return 0;
}
