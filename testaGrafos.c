#include "grafos.h"

void main(){
	
	TipoGrafo* g;
	g = malloc(sizeof(TipoGrafo));
	if (inicializaGrafo(g,6)) printf("\nGrafo de %d vertices iniciado com sucesso", 6);
	
	
	printaGrafo(g);
	
	if(insereAresta(g, 2, 3, 1)) printf("Aresta inserida com sucesso");
	printaGrafo(g);
	
	if(insereAresta(g, 4, 3, 1)) printf("\nAresta inserida com sucesso");
	printaGrafo(g);
	
	if(insereAresta(g, 2, 3, 1)) printf("\nAresta inserida com sucesso");
	printaGrafo(g);
	
	if (checaAdjacencia(g, 2)) printf("\nEncontrado o Vertice %d Entre os adjacentes de 2", checaAdjacencia(g, 2));
	else printf ("Nao foram encontrados nenhum vertice adjacente a 2");
	
	
	buscaProfundidade(g,0,-2,0);

	
}
