#include <stdio.h>
#define MAX_PRODUTOS 5

  struct Produto {
     float valor;
  };

  int main() {
      int n, i;
      float limite;
      int contagem = 0;
      struct Produto produtos[MAX_PRODUTOS];

      printf("Digite o número de produtos (maximo %d): ", MAX_PRODUTOS);
      scanf("%d", &n);

      printf("Digite o valor limite: ");
      scanf("%f", &limite);

      for (i = 0; i < n; i++) {
          printf("Digite o valor do produto %d: ", i + 1);
          scanf("%f", &produtos[i].valor);
      }

      for (i = 0; i < n; i++) {
          if (produtos[i].valor < limite) {
              contagem++;
          }
      }

      printf("Número de produtos com valor abaixo de %.2f: %d\n", limite, contagem);

      return 0;
  }
