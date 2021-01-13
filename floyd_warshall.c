#include<stdio.h> 
#include <limits.h>

//Caso você queira testar em um grafo com um número de vértices diferente, é só modificar esse valor
#define VERTICES 4 

void printSolution(int dist[][VERTICES]) 
{ 
	printf ("A matriz inicial foi modificada para mostar a menor distância entre cada par de vértices:\n"); 
    int i, j;
	for (i = 0; i < VERTICES; i++) 
	{ 
		for (j = 0; j < VERTICES; j++) 
		{ 
			if (dist[i][j] == INT_MAX)
            {
                printf("INT_MAX "); 
            } 	
			else
            {
                printf ("%d \t\t", dist[i][j]);
            }		 
		} 
		printf("\n"); 
	} 
} 

void floyd_warshall (int matriz_adjacencia[][VERTICES]) 
{ 

	int distancia_atual[VERTICES][VERTICES];
    int i, j, k; 

	for (i = 0; i < VERTICES; i++)
    {
        for (j = 0; j < VERTICES; j++)
        {
            distancia_atual[i][j] = matriz_adjacencia[i][j];
        } 
			
    } 		 

	for (k = 0; k < VERTICES; k++) 
	{ 
		for (i = 0; i < VERTICES; i++) 
		{ 

			for (j = 0; j < VERTICES; j++) 
			{ 
                int antes, depois;
                antes = distancia_atual[i][j];
                depois = distancia_atual[i][k] + distancia_atual[k][j];
				if (distancia_atual[i][k] != INT_MAX && distancia_atual[k][j] != INT_MAX && antes > depois) distancia_atual[i][j] = depois; 
			} 
		} 
	} 

	printSolution(distancia_atual); 
} 


void imprimindo_matriz(int matriz[][VERTICES])
{
    int i, j;
    for(i = 0; i < VERTICES; i++)
    {
        for(j = 0; j < VERTICES; j++)
        {
            matriz[i][j] == INT_MAX ? printf("INT_MAX ") : printf("%d \t\t", matriz[i][j]);
        }
        printf("\n");
    }
}

// driver program to test above function 
int main() 
{ 
    /*Aqui você pode colar o seu grafo através da matriz de adjacência, 
    0: distância de um vértice para ele mesmo
    INT_MAX: quando os vértices não são ligados
    peso: quando os vértices são ligados*/
	int matriz_adjacencia[VERTICES][VERTICES] = { {0, 5, INT_MAX, 10}, 
						                          {INT_MAX, 0, 3, INT_MAX}, 
						                          {INT_MAX, INT_MAX, 0, 1}, 
						                          {INT_MAX, INT_MAX, INT_MAX, 0} 
					                            }; 

    printf("Essa é a sua matriz de adjacência:\n\n");
    imprimindo_matriz(matriz_adjacencia);
    printf("\n\n");
    printf("Caso queira modificá-la, faça isso diretamente no código.\n");
    printf("Você também pode mudar o número de vértiices para torná-la maior ou menor\n\n\n");
    printf("--------------------------------------------------------------------------------\n");
	floyd_warshall(matriz_adjacencia); 
	return 0; 
} 
