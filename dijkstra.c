#include <stdio.h>
#include <limits.h>
#define N_MAX 100

int achar_distancia_minima(int distancia[], int flag[], int n) 
{ 
    int minimo = INT_MAX;
    int index_minimo, i; 

    for (i = 0; i < n; i++)
    {
        if (flag[i] == 0 && distancia[i] <= minimo)
        {
            minimo = distancia[i], index_minimo = i;
        } 
    }        
    return index_minimo; 
} 
  
void imprimindo_resultado(int distancias[], int n) 
{ 
    printf("Vértice \t\t distancia do ponto de partida\n"); 
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d \t\t %d\n", i, distancias[i]); 
    }       
}

 void dijkstra(int matriz_adjacencia[][N_MAX], int vertice_partida, int n_vertices) 
 {
    int distancia_minima[N_MAX]; //vai guardar o a menor distância 
    int flag[N_MAX]; //vou guardar 0 e 1, será 1 se o vértice i estiver na menor distância 
    int i, j;
    
    // Todas as distâncias começam como infinito e as flags com false
    for (i = 0; i < n_vertices; i++)
    {
        distancia_minima[i] = INT_MAX;
        flag[i] = 0; 
    }

    //A distância de um vértice para ele mesmo é 0
    distancia_minima[vertice_partida] = 0;

    //Achando a distância mínima para todos os vértices
    int distancia_minima_atual;
    for(j = 0; j < n_vertices - 1; j++)
    {
        //Pegando a menor distância
        distancia_minima_atual = achar_distancia_minima(distancia_minima, flag, n_vertices);
        
        //vértice da distância mínima atual como visitado 
        flag[distancia_minima_atual] = 1; 

        //é necessário atualizar os valores de distancia_minima e dos vértices adjacentes a ele
        int k;

        // só atualiza distancia_minima[distancia_minima_atual] se ele flag = 1
        for(k = 0; k < n_vertices; k++) 
        {
            if((flag[k] == 0) && matriz_adjacencia[distancia_minima_atual][k] && distancia_minima[distancia_minima_atual] != INT_MAX)
            {
                if(distancia_minima[distancia_minima_atual] + matriz_adjacencia[distancia_minima_atual][k] < distancia_minima[k])
                {
                    distancia_minima[k] = distancia_minima[distancia_minima_atual] + matriz_adjacencia[distancia_minima_atual][k];
                }
            }
        }
    }

    imprimindo_resultado(distancia_minima, n_vertices);
           
 }

int main() 
{
    int n_vertices, vertice_partida, i, j;
    printf("Informe o número de vértices:\n");
    scanf("%d", &n_vertices);
    printf("Informe o vértice de partida:\n");
    scanf("%d", &vertice_partida);

    int matriz_adjacencia[N_MAX][N_MAX];
    printf("Informe a matriz de adjacência:\n");

    //leitura da matriz
    for(i = 0; i < n_vertices; i++)
    {
        for(j = 0; j < n_vertices; j++) 
        {
            scanf("%d", &matriz_adjacencia[i][j]);
            //printf("%d ", matriz_adjacencia[i][j]);
        }
        //printf("\n");
    }

    dijkstra(matriz_adjacencia, vertice_partida, n_vertices);

    return 0;
}