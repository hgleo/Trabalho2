/*
Este é um programa em C que implementa um sistema básico de aluguel de carros. O programa permite ao usuário cadastrar carros, listar carros disponíveis, pesquisar carros por placa, modelo ou ano e alugar carros. O programa armazena as informações do carro em uma variedade de estruturas. Cada estrutura representa um carro e contém os seguintes campos: marca, modelo, placa, valor, valor do aluguel, ano e bandeira alugada. O programa é escrito em C e pode ser compilado e executado em um terminal.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Carro{
  char marca[20];
  char modelo[20];
  char placa[7];
  int valor;
  int aluguel;
  int ano;
  int alugado;
};
void liberar_memoria(struct Carro*** carros, int quantidade_carros) {
     for (int i = 0; i < quantidade_carros; i++) {
        free((*carros)[i]);
    }
    free(*carros);
}
void cadastrar_carro(struct Carro*** carros, int* quantidade_carros){
    *carros = (struct Carro**) realloc(*carros, (*quantidade_carros+1) * sizeof(struct Carro*));
    if(carros == NULL){
      printf("Ocorreu um erro. Entre em contato com o administrador. ERRO: 1002\n");
      exit(1);
    }
    (*carros)[*quantidade_carros] = (struct Carro*) malloc(sizeof(struct Carro));
    
    printf("\nDigite a marca do carro: ");
    scanf("%s", (*carros)[*quantidade_carros]->marca);
    printf("Informe o modelo do carro: ");
    scanf("%s", (*carros)[*quantidade_carros]->modelo);
    printf("Informe a placa do carro: ");
    scanf("%s", (*carros)[*quantidade_carros]->placa);
    printf("Informe o ano do carro: ");
    scanf("%d", &(*carros)[*quantidade_carros]->ano);
    printf("Informe o valor do carro: ");
    scanf("%d", &(*carros)[*quantidade_carros]->valor);
    printf("Informe o valor do aluguel em reais/mes do carro: ");
    scanf("%d", &(*carros)[*quantidade_carros]->aluguel);
    printf("Carro cadastrado com sucesso!\n");
    (*carros)[*quantidade_carros]->alugado = 0;

    (*quantidade_carros)++;
}
void exibir_carros(struct Carro*** carros, int quantidade_carros){
  if (quantidade_carros == 0)
  {
    printf("Não há carros disponíveis.\n");
    return;
  }

  printf("\nCarros disponíveis: \n");
  int k=0;
  for (int i = 0; i < quantidade_carros; i++)
  {
      if((*carros)[i]->alugado == 0){
      printf("Marca: %s\n", (*carros)[i]->marca);
      printf("Modelo: %s\n", (*carros)[i]->modelo);
      printf("Placa: %s\n", (*carros)[i]->placa);
      printf("Ano: %d\n", (*carros)[i]->ano);
      printf("Valor: %d\n", (*carros)[i]->valor);
      printf("Aluguel: %d\n", (*carros)[i]->aluguel);
      printf("\n");
      k++;
      }
  }
  if(k==0) printf("Não existem carros disponíveis no momento.\n");
}
void exibir(struct Carro*** carros, int i){

      printf("Marca: %s\n", (*carros)[i]->marca);
      printf("Modelo: %s\n", (*carros)[i]->modelo);
      printf("Placa: %s\n", (*carros)[i]->placa);
      printf("Ano: %d\n", (*carros)[i]->ano);
      printf("Valor: %d\n", (*carros)[i]->valor);
      printf("Aluguel: %d\n", (*carros)[i]->aluguel);
      printf("\n");
}
void pesquisa_carros(struct Carro*** carros, int tipo){
  char placa[7];
  char modelo[20];
  int ano;

  if (tipo == 1)
  {

    printf("\nDigite a placa do veículo a ser pesquisado: ");
    scanf("%s", placa);

    for (int i = 0; i < 100; i++)
    {
      if (strcmp((*carros)[i]->placa, placa) == 0)
      {
        printf("Veiculo encontrado!\n");
        exibir(carros, i);
        return;
      }
  }
      printf("Placa não encontrada!\n");
    }

  if (tipo == 2)
  {

    printf("\nDigite o modelo do veículo a ser pesquisado: ");
    scanf("%s", modelo);

    for (int i = 0; i < 100; i++)
    {
      if (strcmp((*carros)[i]->modelo, modelo) == 0)
      {
        printf("Veículo encontrado!\n");
        exibir(carros, i);
        return;
      }
    }
    printf("Modelo não encontrado!\n");
  }

  if (tipo == 3)
  {

    printf("\nDigite o ano do veículo a ser pesquisado: ");
    scanf("%d", &ano);

    for (int i = 0; i < 100; i++)
    {
      if ((*carros)[i]->ano == ano)
      {
        printf("Veículo encontrado!\n");
        exibir(carros, i);
        return;
      }
    }
    printf("Carro de ano %d não encontrado!\n", ano);
  }
}
void alugar_carro(struct Carro*** carros, int quantidade_carros){

  int escolha = 0;
  char modelo[20];

  printf("\nInforme o modelo do carro que deseja alugar: ");
  scanf("%s", modelo);

  for (int i = 0; i < quantidade_carros; i++)
  {
    if (!(*carros)[i]->alugado && strcmp((*carros)[i]->modelo, modelo) == 0)
    {
      (*carros)[i]->alugado = 1;
      printf("O aluguel deste carro custa %d Reais/mes, deseja prosseguir?\nDigite [1] para sim ou [0] para não\n", (*carros)[i]->aluguel);
      scanf("%d", &escolha);
      if (!escolha)
        printf("O carro não foi alugado - retornando ao  -\n\n");
      else
        printf("O carro foi alugado, parabéns - retornando ao menu -\n\n");
      return;
    }
  }

  printf("Não foi possível alugar o carro informado.\n");
}
void devolver_carro(struct Carro*** carros, int quantidade_carros){
char placa[7];printf("\nDigite a placa do carro que deseja devolver: ");
scanf("%s", placa);

for (int i = 0; i < quantidade_carros; i++){
    if (strcmp((*carros)[i]->placa, placa) == 0)
    {
        if ((*carros)[i]->alugado == 1)
        {
            (*carros)[i]->alugado = 0;
            printf("\nCarro de placa %s devolvido com sucesso!\n", placa);
            return;
        }
        else
        {
            printf("\nO carro de placa %s não está alugado.\n", placa);
            return;
        }
    }
}
printf("\nCarro de placa %s não encontrado.\n", placa);
}
void apagar_carro(struct Carro*** carros, int *quantidade_carros){
  char placa[50];
  printf("Informe a placa do carro que deseja apagar: ");
  scanf("%s", placa);

  for (int i = 0; i < *quantidade_carros; i++)
  {
    if (strcmp((*carros)[i]->placa, placa) == 0)
    {
      for (int j = i; j < *quantidade_carros - 1; j++)
      {
        (*carros)[j] = (*carros)[j + 1];
      }
    
    *carros = (struct Carro**) realloc(*carros, (*quantidade_carros - 1) * sizeof(struct Carro*));
    (*quantidade_carros)--;
    printf("Carro apagado com sucesso!\n\n");
    }
  }
    return;
}
int particionar(struct Carro** carros, int esquerda, int direita) {
  int pivo = carros[direita]->valor;
  int i = esquerda - 1;
  struct Carro* temp;

  for (int j = esquerda; j <= direita - 1; j++) {
    if (carros[j]->valor < pivo) {
      i++;
      temp = carros[i];
      carros[i] = carros[j];
      carros[j] = temp;
    }
  }
  temp = carros[i + 1];
  carros[i + 1] = carros[direita];
  carros[direita] = temp;

  return i + 1;
}
void quickSort(struct Carro** carros, int esquerda, int direita) {
  if (esquerda < direita) {
    int indice_pivo = particionar(carros, esquerda, direita);
    quickSort(carros, esquerda, indice_pivo - 1);
    quickSort(carros, indice_pivo + 1, direita);
  }
}
int main(){
  int opcao = 99, quantidade_carros = 0;
  
  struct Carro** carros = NULL;

  int option = 99;
  int i;
  do{
    printf("\nVoce é um comprador ou um vendedor?\n");
    printf("[1]-> Comprador\n");
    printf("[2]-> Vendedor\n");
    printf("[0]-> Encerrar o programa.\n");
    printf("[->] ");
    scanf("%d", &option);
    system("cls");

  if (option == 1)
  {
    do
    {
      printf("\nEscolha uma opção: \n");
      printf("[1]-> Exibir carros disponíveis\n");
      printf("[2]-> Alugar carro\n");
      printf("[3]-> Devolver carro\n");
      printf("[0]-> Retornar ao menu inicial\n");
      printf("[->] ");
      scanf("%d", &opcao);
      system("cls");
      switch (opcao)
      {
      case 1:
        exibir_carros(&carros, quantidade_carros);
        break;
      case 2:
        alugar_carro(&carros, quantidade_carros);
        break;
      case 3: 
        devolver_carro(&carros, quantidade_carros);
      break;
      case 0:
        break;
      default:
        printf("Opção inválida.\n");
        break;
      }
    } while (opcao != 0);
  }
  if (option == 2)
  {
    do
    {
      ///---------------------------------------------------------
      printf("\nEscolha uma opção: \n");
      printf("[1]-> Cadastrar carro\n");
      printf("[2]-> Exibir carros disponíveis\n");
      printf("[3]-> Pesquisar carros\n");
      printf("[4]-> Apagar carro\n");
      printf("[0]-> Retornar ao menu inicial\n");
      printf("[->] ");
      scanf("%d", &opcao);
      system("cls");

      switch (opcao)
      {
      case 1:
        cadastrar_carro(&carros, &quantidade_carros);
        break;
      case 2:
        exibir_carros(&carros, quantidade_carros);
        break;
      case 3:
        printf("\nEscolha uma opção de pesquisa: \n");
        printf("[1]-> Pesquisa pela Placa \n");
        printf("[2]-> Pesquisa pelo Modelo\n");
        printf("[3]-> Pesquisa pelo Ano\n");
        printf("[->] ");
        scanf("%d", &i);
        pesquisa_carros(&carros, i);
        break;
      case 4:
        apagar_carro(&carros, &quantidade_carros);
        break;
      case 0:
        break;
      default:
        printf("Opção inválida.\n");
        break;
      }
    } while (opcao != 0);
  }
  }while(option!=0);

// ARQUIVOS -- CRIARÁ UM ARQUIVO E IMPRIMIRÁ OS CARROS QUE NÃO FORAM ALUGADOS DURANTE A EXECUÇÃO DO PROGRAMA (ESTARÃO ORDENADOS POR PREÇO)

quickSort(carros, 0, quantidade_carros - 1);
FILE *saida = fopen("carros_sobrando.txt", "w");
if (saida == NULL){
  printf("ERROR: erro ao abrir %s\n", "carros_sobrando.txt");
}
else{
  fprintf(saida, "CARROS QUE AINDA NAO FORAM DEVOLVIDOS:\n");
  for(int i = 0; i < quantidade_carros; i++){
    if(carros[i]->alugado == 1){
      fprintf(saida, "MARCA: %s |\t", carros[i]->marca);
      fprintf(saida, "MODELO: %s |\t", carros[i]->modelo);
      fprintf(saida, "PLACA: %s |\t", carros[i]->placa);
      fprintf(saida, "VALOR: %d \t\n", carros[i]->valor);
    }
  }
}

  fclose(saida);
  liberar_memoria(&carros, quantidade_carros);
  return 0;
}
