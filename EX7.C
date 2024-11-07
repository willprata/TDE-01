#include <stdio.h>
#include <string.h>

#define MAX_CLUBES 10

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

void buscarClubePorID(struct Clube clubes[], int totalClubes, int id) {
    for (int i = 0; i < totalClubes; i++) {
        if (clubes[i].id == id) {
            int pontuacao = calcularPontuacao(clubes[i].vitorias, clubes[i].empates);
            printf("Clube encontrado:\n");
            printf("ID: %d\n", clubes[i].id);
            printf("Nome: %s\n", clubes[i].nome);
            printf("Vitórias: %d\n", clubes[i].vitorias);
            printf("Empates: %d\n", clubes[i].empates);
            printf("Derrotas: %d\n", clubes[i].derrotas);
            printf("Gols Pró: %d\n", clubes[i].gols_pro);
            printf("Gols Contra: %d\n", clubes[i].gols_contra);
            printf("Pontuação: %d\n", pontuacao);
            return;
        }
    }
    printf("Clube com ID %d não encontrado.\n", id);
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

    int idBusca;
    printf("\nDigite o ID do clube que deseja buscar: ");
    scanf("%d", &idBusca);
    buscarClubePorID(clubes, MAX_CLUBES, idBusca);

    return 0;
}
