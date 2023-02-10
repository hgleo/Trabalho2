#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


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
    char marca[20];
    char modelo[20];
    char placa[7];
    int ano;
    int valor; //99.999.999,99
}veiculo;

// FUNÇÕES 

veiculo* cadastroVeiculo(){

    veiculo *v;

    v = (veiculo*) malloc(sizeof(veiculo));

    printf("\n\n-- CADASTRO DO VEÍCULO --");
    printf("\nDigite a marca do carro: ");
    scanf("%s",v->marca);
    printf("Informe o modelo do carro: ");
    scanf("%s",v->modelo);
    printf("Informe a placa do carro: ");
    scanf("%s",v->placa);
    printf("Informe o ano do carro: ");
    scanf("%d",&v->ano);
    while(v->ano < 1850 || v->ano > 2050){
      printf("\nAno Inválido!");
      printf("\nInforme o ano do carro: ");
      scanf("%d",&v->ano);
    }
    printf("Informe o valor do carro: ");
    printf("R$");scanf("%d",&v->valor);

  return v;
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
             
        }

    }
}
void removeVeiculo(){

}
void clientes(){

}

int main(){

  // CRIAR MENU DE INTERAÇÃO DO USUÁRIO COM ACESSO DE VENDEDOR
  // MENUS DIFERENTES PARA OS 2 TIPOS DE ACESSO

  veiculo *p = (veiculo*) malloc(sizeof(veiculo)); // PONTEIRO PARA A STRUCT

  //struct veiculo veiculo[100]; // PASSAR ISSO PARA ALOCAÇÃO DINÂMICA
  int cadastroNum=0; // NUMERO DE CADASTRO DO CARRO
  int opc = 99; // OPÇÃO PARA O CONTROLE DO MENU
  char aux[20]; // AUXILIAR DE PESQUISA MARCA/PLACA

  do{
    
    printf("\n[ NOME DO LUGAR INVENTA UM AI ]");
    printf("\n[1] Cadastrar Veículo");
    printf("\n[2] Remover Veículo");
    printf("\n[3] Pesquisar Veículo");
    printf("\n[0] Sair\n");
    printf("\n[->]");
    scanf("%d",&opc);

    if(opc == 3){
            //system('cls');
            printf("\n-- Escolha a opção da pesquisa --");
            printf("\n[1] Marca");
            printf("\n[2] Placa");
            printf("\n[3] Ano");
            printf("\n[0] Retornar ao menu inicial");
            printf("\n[->]");
            scanf("%d",&opc);

            pesquisa(p,opc);
    }

   switch(opc){

    case 1: 
            
            p[cadastroNum] = cadastroVeiculo();
            cadastroNum++;
            printf("\n\nVEÍCULO CADASTRADO COM SUCESSO!\n");
            
    break;

    case 2:
    printf("OI");
    break;

    case 3:
            
    break;

    case 0:
      exit(0);
    break;
   } 

  }while(opc != 0);
}