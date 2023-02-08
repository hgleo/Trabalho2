#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include <windows.h> // SLEEP

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

typedef struct veiculo{
    char marca[50];
    char placa[7];
    int ano;
    int valor; //99.999.999,99
}veiculo;

// FUNÇÕES 
struct veiculo cadastroVeiculo(){

    struct veiculo veiculo;
    int v;
    printf("\n\n-- CADASTRO DO VEÍCULO --");
    printf("\nMARCA DO VEÍCULO: ");
    scanf("%s",veiculo.marca);
    printf("\nPLACA :");
    scanf("%s",veiculo.placa);
    printf("\nANO: ");
    scanf("%d",&veiculo.ano);
    while(veiculo.ano < 1850 || veiculo.ano > 2050){
      printf("\n ANO INVÁLIDO!");
      printf("\nANO: ");
      scanf("%d",&veiculo.ano);
    }
    printf("\nVALOR :");
    scanf("%d",&veiculo.valor);

  return veiculo;
}

void pesquisa(struct veiculo veiculo[], int n){
    // N INDICA QUAL MÉTODO DE BUSCA: [1] MARCA [2] PLACA [3] ANO
    int auxI;
    char auxC;
    if(n==1){
        printf("\nDIGITE A MARCA DO VEÍCULO: ");
        scanf("%s",auxC);

        for(int i=0; i <100; i++){
            if(toupper(veiculo[i].marca) == toupper(auxC)){
              printf("\nVEÍCULO %d ENCONTRADO COM SUCESSO!\n", i);
              printf("\nMARCA DO VEÍCULO: %s",veiculo[i].marca);
              printf("\nPLACA : %s",veiculo[i].placa);
              printf("\nANO: %d",veiculo[i].ano);
              printf("\nVALOR : %d",veiculo[i].valor);
              auxI = 99;
            }; 
        }
        if(auxI == 99){
              printf("\nVEÍCULO NÃO FOI ENCONTRADO!\n");
              //Sleep(5000);
        }
    }
    if(n==2){
          printf("\nDIGITE A PLACA DO VEÍCULO: ");
          scanf("%s",auxC);
        for(int i=0; i <100; i++){
            if(toupper(veiculo[i].placa) == toupper(auxC)){
              printf("\nVEÍCULO %d ENCONTRADO COM SUCESSO!\n", i);
              printf("\nMARCA DO VEÍCULO: %s",veiculo[i].marca);
              printf("\nPLACA : %s",veiculo[i].placa);
              printf("\nANO: %d",veiculo[i].ano);
              printf("\nVALOR : %d",veiculo[i].valor);
              auxI = 99;
            }; 
        }
        if(auxI == 99){
              printf("\nVEÍCULO NÃO FOI ENCONTRADO!\n");
              //Sleep(5000);
        }

    }
    if(n==3){
          printf("\nDIGITE O ANO DO VEÍCULO: ");
          scanf("%d",&auxI);

        for(int i=0; i <100; i++){
            if(toupper(veiculo[i].ano) == toupper(auxI)){
              printf("\nVEÍCULO %d ENCONTRADO COM SUCESSO!\n", i);
              printf("\nMARCA DO VEÍCULO: %s",veiculo[i].marca);
              printf("\nPLACA : %s",veiculo[i].placa);
              printf("\nANO: %d",veiculo[i].ano);
              printf("\nVALOR : %d",veiculo[i].valor);
              auxI = 99;
            }; 
        }
        if(auxI == 99){
              printf("\nVEÍCULO NÃO FOI ENCONTRADO!\n");
              //Sleep(5000);
        }

    }
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
  char aux[50]; // AUXILIAR DE PESQUISA MARCA/PLACA

  do{
    system("cls");
    printf("[ NOME DO LUGAR INVENTA UM AI ]\n");
    printf("[1] CADASTRAR VEÍCULO\n");
    printf("[2] REMOVER VEÍCULO\n");
    printf("[3] PESQUISAR VEÍCULO\n");
    printf("[0] SAIR\n");
    printf("[->]");
    scanf("%d",&opc);

    if(opc == 3){
            //system('cls');
            printf("\n-- ESCOLHA A OPÇÃO DE PESQUISA --");
            printf("\n[1] MARCA");
            printf("\n[2] PLACA");
            printf("\n[3] ANO");
            printf("\n[0] RETORNAR AO MENU INICIAL");
            printf("\n[->]");
            scanf("%d",&opc);

            pesquisa(veiculo,opc);
    }

   switch(opc){

    case 1: 
            system("cls");
            veiculo[cadastroNum] = cadastroVeiculo();
            cadastroNum++;
            printf("\n\nVEÍCULO CADASTRADO COM SUCESSO!");
            //Sleep(1000);
    break;

    case 2:
    break;

    case 3:
            system("cls");
            
    break;

    case 0:
      exit(0);
    break;
   } 

  }while(opc != 0);
}

