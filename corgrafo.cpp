#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Fun��o para encontrar a colora��o do grafo
void greedyColoring(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int result[MAX_VERTICES]; // Array para armazenar as cores dos v�rtices

    // Inicializa a cor do primeiro v�rtice como 0
    result[0] = 0;

    // Inicializa as cores de todos os outros v�rtices como -1 (n�o coloridos)
    for (int i = 1; i < numVertices; i++) {
        result[i] = -1;
    }

    // Array para verificar cores dispon�veis (inicialmente todas dispon�veis)
    bool available[MAX_VERTICES];
    
    // Atribuir cores a todos os outros v�rtices
    for (int u = 1; u < numVertices; u++) {
        // Inicializar todas as cores como dispon�veis
        for (int i = 0; i < numVertices; i++) {
            available[i] = true;
        }

        // Marcar as cores dos vizinhos como indispon�veis
        printf("\nAnalisando o v�rtice %d:\n", u);
        for (int v = 0; v < numVertices; v++) {
            if (graph[u][v] == 1 && result[v] != -1) {
                available[result[v]] = false;
                printf(" - Vertice %d e adjacente a %d e tem cor %d, marcando cor como indisponivel\n", u, v, result[v]);
            }
        }

        // Encontrar a menor cor dispon�vel
        int cr;
        for (cr = 0; cr < numVertices; cr++) {
            if (available[cr]) {
                result[u] = cr; // Atribuir a menor cor dispon�vel
                break;
            }
        }
        printf(" - Vertice %d recebe a cor %d\n", u, result[u]);
    }

    // Imprimir as cores atribu�das
    printf("\nResultado final da coloracao:\n");
    printf("Vertice\tCor\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d\t%d\n", i, result[i]);
    }
}

int main() {
    int numVertices = 6;
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 0, 1, 0, 0}, // V�rtice 0
        {1, 0, 1, 0, 1, 0}, // V�rtice 1
        {0, 1, 0, 0, 0, 1}, // V�rtice 2
        {1, 0, 0, 0, 1, 0}, // V�rtice 3
        {0, 1, 0, 1, 0, 1}, // V�rtice 4
        {0, 0, 1, 0, 1, 0}  // V�rtice 5
    };

    greedyColoring(graph, numVertices);

    return 0;
}


