#include <stdio.h>
#include <string.h>

#define MAX_CLUBES 3

struct Clube {
    int id;
    char nome[50];
    int vitorias;
    int empates;
    int derrotas;
    int gols_pro;
    int gols_contra;
};

int calcularPontuacao(int vitorias, int empates) {
    return (vitorias * 3) + (empates * 1);
}

int main() {
    struct Clube clubes[MAX_CLUBES];
    int i;

    for (i = 0; i < MAX_CLUBES; i++) {
        printf("Cadastro do Clube %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &clubes[i].id);
        printf("Nome: ");
        getchar(); 
        fgets(clubes[i].nome, sizeof(clubes[i].nome), stdin);
        clubes[i].nome[strcspn(clubes[i].nome, "\n")] = '\0'; 
        printf("Vitórias: ");
        scanf("%d", &clubes[i].vitorias);
        printf("Empates: ");
        scanf("%d", &clubes[i].empates);
        printf("Derrotas: ");
        scanf("%d", &clubes[i].derrotas);
        printf("Gols Pró: ");
        scanf("%d", &clubes[i].gols_pro);
        printf("Gols Contra: ");
        scanf("%d", &clubes[i].gols_contra);
        printf("\n");
    }

    printf("\nPontuação dos Clubes:\n");
    for (i = 0; i < MAX_CLUBES; i++) {
        int pontuacao = calcularPontuacao(clubes[i].vitorias, clubes[i].empates);
        printf("Clube ID: %d, Nome: %s, Pontuação: %d\n", clubes[i].id, clubes[i].nome, pontuacao);
    }

    return 0;
}
