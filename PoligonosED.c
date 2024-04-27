#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definindo a estrutura para representar um ponto
typedef struct {
    float X;
    float Y;
} Ponto;

// Função para calcular a área de um triângulo formado por três pontos A, B e C
float areaTriangulo(Ponto A, Ponto B, Ponto C) {
    return fabs((A.X * (B.Y - C.Y) + B.X * (C.Y - A.Y) + C.X * (A.Y - B.Y)) / 2.0);
}

// Função para calcular a área do polígono
float areaPoligono(FILE *arquivo) {
    int numVertices;
    fscanf(arquivo, "%d", &numVertices);

    Ponto A, B, C;
    fscanf(arquivo, "%f %f", &A.X, &A.Y);
    fscanf(arquivo, "%f %f", &B.X, &B.Y);

    float areaTotal = 0;
    for (int i = 2; i < numVertices; i++) {
        fscanf(arquivo, "%f %f", &C.X, &C.Y);
        areaTotal += areaTriangulo(A, B, C);
        B = C; // Avançar para o próximo ponto
    }

    return areaTotal;
}

int main() {
    FILE *arquivo;
    arquivo = fopen("dados.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        perror("fopen");
        return 1;
    }

    float area = areaPoligono(arquivo);
    printf("A area do poligono e %.2f\n", area);

    fclose(arquivo);
    return 0;
}