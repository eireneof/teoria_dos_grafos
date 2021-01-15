#include <stdio.h>
#include <stdlib.h>
 
#define INF 50000
 
typedef struct Dados {
    int origem, destino, peso;
}Dados;
 
typedef struct Grafo {
    Dados vertices[INF];
}Grafo;
 
void imprimir(int distancia[], int num_vertices) {
    for(int i = 0; i < num_vertices; i++) {
        printf("Vertice: %d | Distancia: %d\n", i, distancia[i]);
    }
}
 
void BellmanFord(int num_vertices, int num_arestas, Grafo *gf, int inicio) {
    int distancia[num_vertices];
 
    for(int i = 0; i < num_vertices; i++) { // inicializa a distancia de todos os vertices.
        distancia[i] = INF;
    }
    distancia[inicio] = 0; // e deixa o vertice de inicio com distancia igual a zero;
 
    for(int i = 0; i < num_vertices; i++) {
        for(int j = 0; j < num_arestas; j++) {
            int origem = gf->vertices[j].origem;
            int destino = gf->vertices[j].destino;
            int peso = gf->vertices[j].peso;
            if (distancia[origem] != INF && distancia[origem] + peso < distancia[destino]) {
                distancia[destino] = distancia[origem] + peso;
            }
        }
    }
    imprimir(distancia, num_vertices);
    return;
}
 
int main() {
    int num_vertices, num_arestas, i = 0;
    scanf("%d %d", &num_vertices, &num_arestas);
 
    Grafo * grafo = (Grafo*) malloc(sizeof(Grafo));
 
    int a, b, c;

    while(scanf("%d %d %d", &a, &b, &c) != EOF) {
        grafo->vertices[i].origem = a;
        grafo->vertices[i].destino = b;
        grafo->vertices[i].peso = c;
        i += 1;
    }

    BellmanFord(num_vertices, num_arestas, grafo, 0);
}