#include "grafos.h"

void main(){
	
	TipoGrafo* g;
	g = malloc(sizeof(TipoGrafo));
	if (inicializaGrafo(g,6)) printf("\nGrafo de %d vertices iniciado com sucesso", 6);
	
	
	printaGrafo(g);
	
	if(insereAresta(g, 2, 3)) printf("Aresta inserida com sucesso");
	printaGrafo(g);
	
	if(insereAresta(g, 4, 3)) printf("\nAresta inserida com sucesso");
	printaGrafo(g);
	
	if(insereAresta(g, 2, 3)) printf("\nAresta inserida com sucesso");
	printaGrafo(g);
	
	buscaProfundidade(g);
	
}
