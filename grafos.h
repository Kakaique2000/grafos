#define MAXNUMVERTICES 100
#define AN -1
#define VERTICE_INVALIDO -1

/* cores para busca em profundidade */
#define BRANCO 0
#define CINZA 1
#define PRETO 2

#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>

typedef int TipoPeso;

typedef struct {
	TipoPeso mat[MAXNUMVERTICES + 1][MAXNUMVERTICES + 1];
	int numVertices;
	int numArestas;
	
	
} TipoGrafo;

typedef int TipoApontador;

/* Inicializa o Grafo g (Ja alocado) e coloca o valor de AN em cada vértice */

bool inicializaGrafo (TipoGrafo* g, int nv){
	if(nv>MAXNUMVERTICES){
		printf("ERRO: numero de vertices acima do limite permitido: %d", MAXNUMVERTICES);
		return false;
	}
	if(nv<=0){
		printf("ERRO: numero de vertices deve ser positivo");
		return false;
	}
	g->numVertices = nv;
	int i, j;
	for(i = 0; i<=nv; i++)
		for (j = 0; j<=nv; j++)
		g->mat[i][j] = AN;
	return true;
}

/* printa a matriz de adjacência na tela */

void printaGrafo (TipoGrafo* g){
	
	int nv = g->numVertices;
	int i,j;
	
	printf("\n  ");

	
	for(i = -1; i<nv; i++)
	{
		if(i!=-1) printf("\n%d ", i);
		for(j = 0; j<nv; j++){
			if (i==-1) printf("  %d", j);
			else if (g->mat[i][j] == -1) printf(" %d", g->mat[i][j]);
			else printf("  %d", g->mat[i][j]);
		}
	}
	printf("\n");
}

/*Insere uma aresta no grafo */

bool insereAresta(TipoGrafo *g, int vInicial, int vFinal){
	if(vInicial > g->numVertices){
		printf("valor do Vertice Inicial acima do numero de vertices do grafo : %d", g->numVertices);
		return false;
	}
	if(vInicial <= 0){
		printf("valor do Vertice Inicial nao pode ser negativo");
		return false;
	}
	if(vFinal > g->numVertices){
		printf("valor do Vertice Final acima do numero de vertices do grafo : %d", g->numVertices);
		return false;
	}
	if(vFinal <= 0){
		printf("valor do Vertice Final nao pode ser negativo");
		return false;
	}
	
	if(g->mat[vInicial][vFinal] == 1){
		printf("Ja existe uma aresta identica a estes vertices");
		return false;
	}
	
	g->mat[vInicial][vFinal] = 1;
	return true;	
}

/*Remove uma aresta no grafo */

bool removeAresta(TipoGrafo *g, int vInicial, int vFinal){
	if(vInicial > g->numVertices){
		printf("valor do Vertice Inicial acima do numero de vertices do grafo : %d", g->numVertices);
		return false;
	}
	if(vInicial <= 0){
		printf("valor do Vertice Inicial nao pode ser negativo");
		return false;
	}
	if(vFinal > g->numVertices){
		printf("valor do Vertice Final acima do numero de vertices do grafo : %d", g->numVertices);
		return false;
	}
	if(vFinal <= 0){
		printf("valor do Vertice Final nao pode ser negativo");
		return false;
	}
	
	if(g->mat[vInicial][vFinal] != 1){
		printf("Nao existe aresta nestes vertices");
		return false;
	}
	
	g->mat[vInicial][vFinal] = 0;
	return true;	
	
}

void buscaProfundidade (TipoGrafo* g){
	int nv = g->numVertices;
	int cores[nv];
	int passos = 0;
	int vAtual = 0;
	int i,j;
	for(i = 0; i<nv; i++)
	cores[i] = BRANCO;
	
	int iter = 0;
	while(vAtual<nv){
		
	//TODO...
	
	
	for(j = 0; j<nv; j++)
	printf("cores[%d]: %d", j, cores[j]);
	
	
	
	
	
}






