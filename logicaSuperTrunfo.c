#include <stdio.h>

struct Carta {
    char estado[3];
    char codigo[5];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

void cadastrarCarta(struct Carta *carta) {
    printf("Estado (ex: SP): ");
    scanf("%s", carta->estado);

    printf("Código da carta (ex: A01): ");
    scanf("%s", carta->codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]s", carta->nomeCidade);

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (km²): ");
    scanf("%f", &carta->area);

    printf("PIB (bilhões): ");
    scanf("%f", &carta->pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1000000000) / carta->populacao;
}

void exibirCarta(struct Carta carta) {
    printf("\n--- Carta %s ---\n", carta.codigo);
    printf("Estado: %s\n", carta.estado);
    printf("Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: %.2f reais\n", carta.pibPerCapita);
}

void compararCartas(struct Carta c1, struct Carta c2) {

    printf("\nComparando as cartas pelo atributo: PIB per capita\n");
    printf("%s: %.2f reais\n", c1.nomeCidade, c1.pibPerCapita);
    printf("%s: %.2f reais\n", c2.nomeCidade, c2.pibPerCapita);

    if (c1.pibPerCapita > c2.pibPerCapita) {
        printf("Vencedora: %s (PIB per capita maior)\n", c1.nomeCidade);
    } else if (c2.pibPerCapita > c1.pibPerCapita) {
        printf("Vencedora: %s (PIB per capita maior)\n", c2.nomeCidade);
    } else {
        printf("Empate! As duas cidades possuem o mesmo PIB per capita.\n");
    }
}

int main() {
    struct Carta carta1, carta2;

    printf("Cadastro da Carta 1:\n");
    cadastrarCarta(&carta1);

    printf("\nCadastro da Carta 2:\n");
    cadastrarCarta(&carta2);

    exibirCarta(carta1);
    exibirCarta(carta2);

    compararCartas(carta1, carta2);

    return 0;
}
