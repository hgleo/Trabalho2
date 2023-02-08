#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Carro {
    char marca[50];
    char placa[50];
    int ano;
    int alugado;
};

int main() {
    int numCarros = 0;
    struct Carro *carro = malloc(MAX * sizeof(struct Carro));

    while (1) {
        printf("1. Adicionar carro\n");
        printf("2. Alugar carro\n");
        printf("3. Devolver carro\n");
        printf("4. Listar carros disponíveis\n");
        printf("5. Sair\n");
        printf("\nSelecione uma opção: ");

        int opc;
        scanf("%d", &opc);

        if (opc == 1) {
            if (numCarros == MAX) {
                printf("Não é possível adicionar mais carros. Aumente o tamanho do vetor.\n");
                continue;
            }

            printf("Marca: ");
            scanf("%s", carro[numCarros].marca);

            printf("Placa: ");
            scanf("%s", carro[numCarros].placa);

            printf("Ano: ");
            scanf("%d", &carro[numCarros].ano);

            carro[numCarros].alugado = 0;
            numCarros++;
        } else if (opc == 2) {
            char marca[50];
            printf("Marca do carro a ser alugado: ");
            scanf("%s", marca);

            int i;
            for (i = 0; i < numCarros; i++) {
                if (!strcmp(carro[i].marca, marca) && !carro[i].alugado) {
                    carro[i].alugado = 1;
                    printf("Carro alugado com sucesso!\n");
                    break;
                }
            }

            if (i == numCarros) {
                printf("Carro não disponível para aluguel.\n");
            }
        } else if (opc == 3) {
            char marca[50];
            printf("Marca do carro a ser devolvido: ");
            scanf("%s", marca);

            int i;
            for (i = 0; i < numCarros; i++) {
                if (!strcmp(carro[i].marca, marca) && carro[i].alugado) {
                    carro[i].alugado = 0;
                    printf("Carro devolvido com sucesso!\n");
                    break;
                }
            }

            if (i == numCarros) {
                printf("Carro não encontrado ou já devolvido.\n");
            }
        } else if (opc == 4) {
            printf("Carros disponíveis:\n");
            for (int i = 0; i < numCarros; i++) {
                if (!carro[i].alugado) {
                    printf("Marca: %s, Placa: %s, Ano: %d\n", carro[i].marca, carro[i].placa, carro[i].ano);
                }
            }
        } else if (opc == 5) {
            break;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    free(carro);
    return 0;
}
