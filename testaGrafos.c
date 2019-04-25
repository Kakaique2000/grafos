#include "grafos.h"

int main(int argc, char *argv[]){
	
	if(argc != 3){
            printf("Insira corretamente 2 argumentos");
            exit(-1);
            }
            
	TipoGrafo* g;
	TipoGrafo* arvore;
	g = malloc(sizeof(TipoGrafo));
	arvore = malloc(sizeof(TipoGrafo));
	int i = 0;

   
   FILE *grafoInput = fopen(argv[1], "r");
   FILE *grafoOutput = fopen(argv[2], "w");
   
   if(grafoInput == NULL){
                 printf("Nao foi possivel abrir o arquivo %s", argv[1]);
                 exit(-1);
                 }
                 
    if(grafoOutput == NULL){
                 printf("Nao foi possivel salvar o arquivo o arquivo %s", argv[2]);
                 exit(-1);
                 }             
   


   char ch;
   char arquivoContent[1000];
   int cont = 0;
   while((ch = fgetc(grafoInput)) != EOF){
             arquivoContent[cont] = ch;
             cont++;
             }
             



  decodificaGrafo(g, arquivoContent);
  
  
  
  //prin(g, arvore);
 
  //gravaArquivo(grafoOutput, arvore);
  buscaLargura(g, 0);
  
  system("PAUSE");

	
}
