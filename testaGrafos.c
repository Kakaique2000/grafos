#include "grafos.h"

int main(){
	
	TipoGrafo* g;
	TipoGrafo* arvore;
	g = malloc(sizeof(TipoGrafo));
	arvore = malloc(sizeof(TipoGrafo));
	
	
	if (inicializaGrafo(g,7)) printf("\nGrafo de %d vertices iniciado com sucesso\n", 7);
		
insereAresta(g, 0, 1, 1);
insereAresta(g, 1, 0, 1);
insereAresta(g, 0, 3, 4);
insereAresta(g, 3, 0, 4);
insereAresta(g, 1, 2, 2);
insereAresta(g, 2, 1, 2);
insereAresta(g, 1, 3, 6);
insereAresta(g, 3, 1, 6);
insereAresta(g, 1, 4, 4);
insereAresta(g, 4, 1, 4);
insereAresta(g, 2, 4, 5);
insereAresta(g, 4, 2, 5);
insereAresta(g, 2, 5, 6);
insereAresta(g, 5, 2, 6);
insereAresta(g, 3, 4, 3);
insereAresta(g, 4, 3, 3);
insereAresta(g, 3, 6, 4);
insereAresta(g, 6, 3, 4);
insereAresta(g, 4, 5, 8);
insereAresta(g, 5, 4, 8);
insereAresta(g, 4, 6, 7);
insereAresta(g, 6, 4, 7);
insereAresta(g, 5, 6, 3);
insereAresta(g, 6, 5, 3);
	//printf("%d %d\n", g->numVertices, g->numArestas);

	
	
	prin(g, arvore);
	
	printaGrafo3(arvore);
	
	
	
	
	
	system("PAUSE");

	
}
