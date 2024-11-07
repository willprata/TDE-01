#include <stdio.h>

#define MAX_PRODUTOS 5

struct Produto {
    int id;             
    char nome[50];            
};

int main() {
    int n, i, idBusca;
    float limite;
    int contagem = 0;
    struct Produto produtos[MAX_PRODUTOS];

    printf("Digite o número de produtos (maximo %d): ", MAX_PRODUTOS);
    scanf("%d", &n);

    if (n > MAX_PRODUTOS || n <= 0) {
        printf("Número de produtos inválido!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        produtos[i].id = i + 1;  
        printf("Produto %d:\n", i + 1);
        printf("Digite o nome: ");
        scanf("%s", produtos[i].nome);
    }

    printf("Digite o ID do produto que deseja buscar: ");
    scanf("%d", &idBusca);

    if (idBusca > 0 && idBusca <= n) {
        printf("Produto encontrado:\n");
        printf("ID: %d\n", produtos[idBusca - 1].id);
        printf("Nome: %s\n", produtos[idBusca - 1].nome);
    } else {
        printf("Produto com ID %d não encontrado.\n", idBusca);
    }

    return 0;
}
