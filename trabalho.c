#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Permissões vendedor

//     Alocar quantidade de vagas na garagem;
//     Realocar quantidade de vagas;
//     Cadastrar novo carro;
//     Precisará de algumas informações: preço, modelo, marca, ano, etc.
//     Remover carro;
//     Checar quantidade de clientes, e seus nomes;
//     Permissões comprador:
//     Comprar carro;
//     Alugar carro;
//     Ir embora (Encerra Programa);

// O sistema de identificação (vendedor ou comprador), será administrado por base de um banco de 
// dados improvisado, utilizando arquivos

typedef struct veiculo{
    char marca[50];
    char placa[7];
    int ano;
    char valor[12];//99.999.999,99
}veiculo;

// FUNÇÕES 
struct veiculo cadastroVeiculo(){

    struct veiculo veiculo;

    printf("\n\nCADASTRO DO VEÍCULO");
    printf("\nMARCA DO VEÍCULO: ");
    scanf("%s",veiculo.marca);
    printf("\nPLACA :");
    scanf("%s",veiculo.placa);
    printf("\nANO: ");
    scanf("%d",&veiculo.ano);
    printf("\nVALOR :");
    scanf("%s",veiculo.valor);

  return veiculo;
}

void removeVeiculo(){

}
void clientes(){

}
void veiculos(){

}

int main(){

  // CRIAR MENU DE INTERAÇÃO DO USUÁRIO COM ACESSO DE VENDEDOR
  // MENUS DIFERENTES PARA OS 2 TIPOS DE ACESSO

  struct veiculo veiculo[100]; // PASSAR ISSO PARA ALOCAÇÃO DINÂMICA
  int cadastroNum=0;
  int opc = 99; // OPÇÃO PARA O CONTROLE DO MENU

  do{
    printf("[1] CADASTRAR VEÍCULO\n");
    printf("[2] REMOVER VEÍCULO\n");
    printf("[3] PESQUISAR VEÍCULO\n");
    printf("[0] SAIR\n");
    printf("[->]");
    scanf("%d",&opc);

   switch(opc){

    case 1: veiculo[cadastroNum] = cadastroVeiculo();
    cadastroNum++;
    break;

    case 2:
    break;

    case 3:
    break;
   } 

  }while(opc != 0);
  return 0;
}

