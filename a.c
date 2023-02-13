#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEHICLES 100
#define MAX_NAME 50

typedef struct {
  char name[MAX_NAME];
  int year;
  int rented;
} Vehicle;

Vehicle vehicles[MAX_VEHICLES];
int nVehicles = 0;

void readVehiclesFromFile(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Erro ao abrir arquivo de veículos.\n");
    exit(1);
  }

  while (fscanf(fp, "%s %d", vehicles[nVehicles].name, &vehicles[nVehicles].year) == 2) {
    vehicles[nVehicles].rented = 0;
    nVehicles++;
  }

  fclose(fp);
}

void writeVehiclesToFile(char *filename) {
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    printf("Erro ao abrir arquivo de veículos.\n");
    exit(1);
  }

  for (int i = 0; i < nVehicles; i++) {
    fprintf(fp, "%s %d\n", vehicles[i].name, vehicles[i].year);
  }

  fclose(fp);
}

void listVehicles() {
  printf("Veículos disponíveis:\n");
  for (int i = 0; i < nVehicles; i++) {
    if (!vehicles[i].rented) {
      printf("%d. %s, %d\n", i + 1, vehicles[i].name, vehicles[i].year);
    }
  }
}

void rentVehicle(int index) {
  if (index < 0 || index >= nVehicles) {
    printf("Veículo inválido.\n");
    return;
  }
  if (vehicles[index].rented) {
    printf("Veículo já alugado.\n");
    return;
  }
  vehicles[index].rented = 1;
  printf("Veículo alugado com sucesso.\n");
}

void returnVehicle(int index) {
  if (index < 0 || index >= nVehicles) {
    printf("Veículo inválido.\n");
    return;
  }
  if (!vehicles[index].rented) {
    printf("Veículo não alugado.\n");
    return;
  }
  vehicles[index].rented = 0;
  printf("Veículo devolvido com sucesso.\n");
}

int main() {
  char filename[MAX_NAME];

  printf("Informe o nome do arquivo de veículos: ");
  scanf("%s", filename);

  readVehiclesFromFile(filename);

  int option;
  do {
    printf("\nMenu:\n");
printf("1. Listar veículos\n");
printf("2. Alugar veículo\n");
printf("3. Devolver veículo\n");
printf("4. Sair\n");
printf("Opção: ");
scanf("%d", &option);
switch (option) {
case 1:
listVehicles();
break;
case 2: {
int index;
printf("Informe o número do veículo: ");
scanf("%d", &index);
rentVehicle(index - 1);
break;
}
case 3: {
int index;
printf("Informe o número do veículo: ");
scanf("%d", &index);
returnVehicle(index - 1);
break;
}
case 4:
break;
default:
printf("Opção inválida.\n");
break;
}
} while (option != 4);

writeVehiclesToFile("carro.txt");

return 0;
}
