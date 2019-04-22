#include "grafos.h"

int main(){
	
	TipoGrafo* g;
	TipoGrafo* arvore;
	g = malloc(sizeof(TipoGrafo));
	arvore = malloc(sizeof(TipoGrafo));
	
	
	if (inicializaGrafo(g,7)) printf("\nGrafo de %d vertices iniciado com sucesso\n", 7);
		
	insereAresta(g, 0, 1, 8);
	insereAresta(g, 1, 0, 8);
	insereAresta(g, 0, 2, 2);
	insereAresta(g, 2, 0, 2);
	insereAresta(g, 0, 3, 11);
	insereAresta(g, 3, 0, 11);
	insereAresta(g, 1, 3, 2);
	insereAresta(g, 3, 1, 2);
	insereAresta(g, 1, 4, 4);
	insereAresta(g, 4, 1, 4);
	insereAresta(g, 2, 3, 8);
	insereAresta(g, 3, 2, 8);
	insereAresta(g, 2, 5, 5);
	insereAresta(g, 5, 2, 5);
	insereAresta(g, 3, 5, 13);
	insereAresta(g, 5, 3, 13);
	insereAresta(g, 3, 6, 8);
	insereAresta(g, 6, 3, 8);
	insereAresta(g, 4, 6, 1);
	insereAresta(g, 6, 4, 1);
	insereAresta(g, 5, 6, 3);
    insereAresta(g, 6, 5, 3);

	printf("%d %d\n", g->numVertices, g->numArestas);

	
	
	prin(g, arvore);
	
	printaGrafo(arvore);
	
	
	
	
	
	system("PAUSE");

	
}
