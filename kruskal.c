#include <stdio.h>

#define INF 1 << 20

int find(int pai[], int u) { // Retona o nó raiz do qual ele faz parte.
    while(u != pai[u]) { 
        u = pai[u];  
    } 
    return u;
}

int same_tree(int u, int v, int pai[]) { // Verifica se estão na mesma raiz.
    return find(pai, u) == find(pai, v); // se retorna zero é FALSE.
}

void juntar(int u, int v, int pai[]) { // Coloca os dois nós na mesma raiz
    int pai_u = find(pai, u);
    int pai_v = find(pai, v);
    pai[pai_u] = pai[pai_v];
}

int main() {
    int n_vertices, i, j, n, custo_total = 0;
    scanf("%d", &n_vertices);
    int pai[n_vertices];

    int grafo[n_vertices][n_vertices];

    //leitura da matriz
    for(i = 0; i < n_vertices; i++) {
        for(j = 0; j < n_vertices; j++) {
            scanf("%d", &grafo[i][j]);
            if (grafo[i][j] == -1) grafo[i][j] = INF;
            else custo_total += grafo[i][j];
        }
        pai[i] = i; // cada vertice será uma arvore independente.
    }
    int custo_arvore = 0;
    while(n < n_vertices - 1) { // enquanto todos não estiverem na mesma arvore
        int menor = INF, menor_i = INF, menor_j = INF, atual;
        for(i = 0; i < n_vertices; i++) {
            for(j = 0; j < n_vertices; j++) {
                atual = grafo[i][j];
                if (same_tree(i, j, pai) == 0 && atual < menor) {
                    menor = atual;
                    menor_i = i;
                    menor_j = j;
                }
            }
        }
        custo_arvore += menor;
        juntar(menor_i, menor_j, pai);
        n += 1;
    }
    printf("Custo total: %d\nCusto árvore geradora minima: %d\n", custo_total, custo_arvore);
    return 0;
}