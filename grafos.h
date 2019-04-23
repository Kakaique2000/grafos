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
typedef int NO;
typedef int CORES;

typedef struct {
	TipoPeso mat[MAXNUMVERTICES + 1][MAXNUMVERTICES + 1];
	CORES cores[MAXNUMVERTICES + 1];
	int numVertices;
	int numArestas;
	int pesoTotal;
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
	for(i = 0; i<=nv; i++){
		g->cores[i] = BRANCO;
		for (j = 0; j<=nv; j++)
		g->mat[i][j] = AN;
			}
	g->pesoTotal = 0;
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
			else if (g->mat[i][j] == -1) printf("   ", g->mat[i][j]);
			else printf("  %d", g->mat[i][j]);
		}
	}
	printf("\n");
}

void printaGrafo2(TipoGrafo *g){
         	int nv = g->numVertices;
	int i,j;
	
	
printf("\n%d %d", g->numVertices, g->numArestas);
for(i = 0; i<nv; i++){
      for(j = 0; j<nv; j++){
            
            if(g->mat[i][j] == -1) continue;
            else printf("\n%d %d %d",i,j,g->mat[i][j]);
            
            }
      }
      printf("\n");
}

void printaGrafo3 (TipoGrafo *g){
         	int nv = g->numVertices;
	int i,j;
	
	
printf("\n%d", g->pesoTotal);
for(i = 0; i<nv; i++){
      for(j = 0; j<nv; j++){
            
            if(g->mat[i][j] == -1) continue;
            else printf("\n%d %d",i,j);
            
            }
      }
      printf("\n");
}

/*Insere uma aresta no grafo */

bool insereAresta(TipoGrafo *g, int vInicial, int vFinal, int peso){
	if(vInicial > g->numVertices){
		printf("\nvalor do Vertice Inicial acima do numero de vertices do grafo : %d", g->numVertices);
		return false;
	}
	if(vInicial < 0){
		printf("\nvalor do Vertice Inicial nao pode ser negativo");
		return false;
	}
	if(vFinal > g->numVertices){
		printf("\nvalor do Vertice Final acima do numero de vertices do grafo : %d", g->numVertices);
		return false;
	}
	if(vFinal < 0){
		printf("\nvalor do Vertice Final nao pode ser negativo");
		return false;
	}
	if(peso < 0){
		printf("\nValor Invalido para insercao: %d", peso);
		return false;
	}
	g->mat[vInicial][vFinal] = peso;
	g->pesoTotal += peso;
	g->numArestas++;
	return true;	
}

/*Remove uma aresta no grafo */

bool removeAresta(TipoGrafo *g, int vInicial, int vFinal){
	if(vInicial > g->numVertices){
		printf("nvalor do Vertice Inicial acima do numero de vertices do grafo : %d", g->numVertices);
		return false;
	}
	if(vInicial < 0){
		printf("\nvalor do Vertice Inicial nao pode ser negativo");
		return false;
	}
	if(vFinal > g->numVertices){
		printf("\nvalor do Vertice Final acima do numero de vertices do grafo : %d", g->numVertices);
		return false;
	}
	if(vFinal < 0){
		printf("\nvalor do Vertice Final nao pode ser negativo");
		return false;
	}
	
	if(g->mat[vInicial][vFinal] != 1){
		printf("\nNao existe aresta nestes vertices");
		return false;
	}
	
	g->pesoTotal -= g->mat[vInicial][vFinal];
	g->mat[vInicial][vFinal] = -1;
	g->numArestas--;
	return true;	
	
}

NO checaAdjacencia (TipoGrafo* g, int analisando){
	NO i;	
	for(i = 0; i<g->numVertices; i++)
		if(g->mat[analisando][i] != -1 && g->cores[i] == BRANCO) return i;
	return -1;
}

void prin (TipoGrafo* g, TipoGrafo* arvore) {
     
     int conhecidos[g->numVertices];
     int custo[g->numVertices];
     int anterior[g->numVertices];
     inicializaGrafo(arvore, g->numVertices);
     int verticesAdicionados = 0;
     
     int i;
     for(i = 0; i<g->numVertices; i++){
            conhecidos[i] = false;
            custo[i] = 9999999;
            anterior[i]=-1;
     }
     int vInicial = 0;
     int vAtual = vInicial;
     
     //Até o numero de vertices adicionados não for o mesmo numero de vertices
     while(verticesAdicionados < g->numVertices-1){
    
         //Torna o vértice em análise conhecido
         conhecidos[vAtual] = true;
     
         //Verifica os vizinhos do vertice em questão   
         for(i = 0; i<g->numVertices; i++){
            if(g->mat[vAtual][i] != -1) {
                   //Se o custo for menor ele muda
                if(g->mat[vAtual][i]<custo[i]){
                     custo[i] = g->mat[vAtual][i];
                     anterior[i] = vAtual;
                }  
            }    
         }
        //Cicla pelos custos e vai pro vértice que tem o menor peso NAO VISITADO
        int menorPesoNaoVisitado = 999999;
         int menorPesoNaoVisitadoIndex;
         
         for (i = 0; i<g->numVertices; i++){
        
        //Se o vértice i não for conhecido e o custo dele for menor que 9999999 ele guarda os valores
         	if(!conhecidos[i] && custo[i]<menorPesoNaoVisitado){
         		menorPesoNaoVisitado = custo[i];
         		menorPesoNaoVisitadoIndex = i;
         	//	printf("\nMenor Peso nao visitado foi o %d, para o vertice %i", custo[i], i);
         	        
          	}
         }
     
         
      
         
          
         insereAresta(arvore, anterior[menorPesoNaoVisitadoIndex], menorPesoNaoVisitadoIndex, custo[menorPesoNaoVisitadoIndex]);
         printf("\nAresta adicionada: %d %d %d", anterior[menorPesoNaoVisitadoIndex], menorPesoNaoVisitadoIndex, custo[menorPesoNaoVisitadoIndex]);
         vAtual=menorPesoNaoVisitadoIndex;  
         verticesAdicionados++;
         
     }
     
       // for(i = 0; i<g->numVertices; i++){
          //      if(conhecidos[i] && anterior[i]!=-1)   insereAresta(arvore, anterior[i], i, custo[i]);
          //     }
     
}





