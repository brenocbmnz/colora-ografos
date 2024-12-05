#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100


void coloracaoGulosa(int grafo[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int resultado[MAX_VERTICES];
    resultado[0] = 0; // Primeiro vértice colorido com 0

    // Inicializa outros vértices como não coloridos
    for (int i = 1; i < numVertices; i++) {
        resultado[i] = -1;
    }
    
    bool disponivel[MAX_VERTICES];
    
    // Colorir vértices restantes
    for (int u = 1; u < numVertices; u++) {
        // Reiniciar cores disponíveis
        for (int i = 0; i < numVertices; i++) {
            disponivel[i] = true;
        }
        
        // Marcar cores de vértices adjacentes como indisponíveis
        for (int v = 0; v < numVertices; v++) {
            if (grafo[u][v] == 1 && resultado[v] != -1) {
                disponivel[resultado[v]] = false;
            }
        }
        
        // Encontrar a menor cor disponível
        for (int cr = 0; cr < numVertices; cr++) {
            if (disponivel[cr]) {
                resultado[u] = cr;
                break;
            }
        }
    }
    

    printf("\nResultado da Coloração do Grafo:\n");
    printf("Vértice\tCor\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d\t%d\n", i, resultado[i]);
    }
}

int main() {
    int numVertices = 6;
    int grafo[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 0, 1, 0, 0},
        {1, 0, 1, 0, 1, 0},
        {0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 0, 1},
        {0, 0, 1, 0, 1, 0}
    };
    coloracaoGulosa(grafo, numVertices);
    return 0;
}


