#include <stdio.h>
#define MAX_PRODUTOS 5

struct Produto {
    int id; 
    float valor;        
};

int main() {
    int n, i, idBusca, idAtualiza;
    float limite;
    float somaValores = 0.0;
    int contagem = 0;
    struct Produto produtos[MAX_PRODUTOS];

    printf("Digite o número de produtos (maximo %d): ", MAX_PRODUTOS);
    scanf("%d", &n);

    if (n > MAX_PRODUTOS || n <= 0) {
        printf("Número de produtos inválido!\n");
        return 1;
    }

    printf("Digite o valor limite: ");
    scanf("%f", &limite);

    for (i = 0; i < n; i++) {
        produtos[i].id = i + 1;  
        printf("Produto %d:\n", i + 1);
        printf("Digite o valor: ");
        scanf("%f", &produtos[i].valor);

        somaValores += produtos[i].valor;
    }

    for (i = 0; i < n; i++) {
        if (produtos[i].valor < limite) {
            contagem++;
        }
    }

    printf("Número de produtos com valor abaixo de %.2f: %d\n", limite, contagem);

    float media = somaValores / n;
    printf("Média dos preços dos produtos: %.2f\n", media);

    printf("Produtos com valor acima da média:\n");
  
    int produtosAcimaMedia = 0; 
    for (i = 0; i < n; i++) {
        if (produtos[i].valor > media) {
            printf("ID: %d, Valor: %.2f\n",produtos[i].id, produtos[i].valor);
            produtosAcimaMedia++;
        }
    }

    if (produtosAcimaMedia == 0) {
        printf("Nenhum produto com valor acima da média.\n");
    }

    printf("Digite o ID do produto que deseja buscar: ");
    scanf("%d", &idBusca);

    if (idBusca > 0 && idBusca <= n) {
        printf("Produto encontrado:\n");
        printf("ID: %d\n", produtos[idBusca - 1].id);
        printf("Valor: %.2f\n", produtos[idBusca - 1].valor);
    } else {
        printf("Produto com ID %d não encontrado.\n", idBusca);
    }

    printf("Digite o ID do produto que deseja atualizar o valor: ");
    scanf("%d", &idAtualiza);

    if (idAtualiza > 0 && idAtualiza <= n) {
        printf("Produto encontrado:\n");
        printf("ID: %d\n", produtos[idAtualiza - 1].id);
        printf("Valor atual: %.2f\n", produtos[idAtualiza - 1].valor);

        printf("Digite o novo valor: ");
        scanf("%f", &produtos[idAtualiza - 1].valor);

        for (i = 0; i < n; i++) {
            somaValores += produtos[i].valor;
        }

        printf("Valor atualizado com sucesso!\n");
        printf("Novo valor de: %.2f\n", produtos[idAtualiza - 1].valor);
        printf("Nova média dos preços dos produtos: %.2f\n", somaValores / n); 
    } else {
        printf("Produto com ID %d não encontrado.\n", idAtualiza);
    }

    return 0;
}
