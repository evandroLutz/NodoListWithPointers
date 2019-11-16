#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef struct nodo Nodo;



struct nodo{
	int valor;
	Nodo *proximo;	
};


imprime_lista_inicio (Nodo *inicio)



{

	while(inicio)// enquanto o valor proximo dentro da struct for verdadeiro...
	{
		
		
		printf("imprimindo função valor: %d\n", (*inicio).valor);
		inicio = (*inicio).proximo; // joga dentro de inicio o endereço do proximo item da struct
		
	}

	
}



/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	
setlocale(LC_ALL, "Portuguese");


Nodo *nodoaux, *nodoini, *nodofim; // três ponteiros do tipo nodo, um auxiliar, um inicio e um fim.


nodoini = NULL;
nodofim = NULL;

nodoini = (Nodo*) malloc(sizeof(Nodo)); //criando o primeiro Nodo
if (nodoini)
{
	
	(*nodoini).valor = 5;
	(*nodoini).proximo = NULL;
	nodofim = nodoini; //define o ponteiro para o ultimo struct como o ponteiro atual
	
}


nodoaux = (Nodo*) malloc(sizeof(Nodo));
if (nodoaux)
{
	
	(*nodoaux).valor = 6;
	(*nodoini).proximo = nodoaux;
	(*nodoaux).proximo = NULL;
	(*nodofim).proximo = nodoaux; //linka nodo anterior com este
	nodofim = nodoaux; // define o ponteiro para o ultimo struct como o ponteiro atual
	
	
}

nodoaux = (Nodo*) malloc(sizeof(Nodo));
if (nodoaux)
{
	(*nodoaux).valor = 7;
	(*nodoaux).proximo = NULL;
	(*nodofim).proximo = nodoaux;
	nodofim = nodoaux;
	
	
	
	
}


nodoaux = nodoini;
while (nodoaux)
{
	printf("Valor : %d\n", (*nodoaux).valor);
	printf("Endereço %d\n", nodoaux);
	nodoaux = (*nodoaux).proximo;	
	
}

printf("___________________________________________________________\n");


imprime_lista_inicio(nodoini); //questão 3





printf("___________________________________________________________\n");
printf("Imprimindo função novamente após inserção de novo nodo no inicio:\n");
nodoaux = (Nodo*) malloc(sizeof(Nodo)); //questão 4
if (nodoaux)
{
	(*nodoaux).valor = 4;
	(*nodoaux).proximo = nodoini;
	nodoini = nodoaux;
	
	
	
	
}


imprime_lista_inicio(nodoini);

printf("___________________________________________________________\n");
printf("Imprimindo função novamente após inserção de novo nodo no final:\n");

nodoaux = (Nodo*) malloc(sizeof(Nodo));
if (nodoaux)//questão 5
{
	(*nodoaux).valor = 77;
	(*nodofim).proximo = nodoaux;
	nodofim = nodoaux;
	(*nodofim).proximo = NULL;
	nodoaux = nodoini;
		while(nodoaux)
		{
		
			printf("imprimindo função valor: %d\n",(*nodoaux).valor);		    
			nodoaux = (*nodoaux).proximo;
			
		}	
	
	
}

printf("___________________________________________________________\n");
printf("Imprimindo função novamente após liberar o primeiro nodo:\n");

nodoaux = nodoini; //questão 6
free (nodoini);

nodoini = (*nodoaux).proximo;
nodoaux = nodoini;
		imprime_lista_inicio(nodoini);


printf("___________________________________________________________\n");
printf("Imprimindo função novamente após inserção de novo nodo no inicio:\n");

nodoaux = (Nodo*) malloc(sizeof(Nodo));//questão 7
if (nodoaux)
{
	(*nodoaux).valor = 33;
	(*nodoaux).proximo = nodoini;
	  nodoini = nodoaux;
	 
		imprime_lista_inicio(nodoini);	
	
	
}


 nodoaux = nodoini;
  while (nodoaux) //questão 8
	
   {
  	  if((*nodoaux).proximo == nodofim)
  	  {
		//	printf("%d\n", (*nodoaux).valor); //apenas para testar se era o último
			
			free(nodofim);
			nodofim = nodoaux;
		    (*nodoaux).proximo = NULL;
			
		}   
    nodoaux = (*nodoaux).proximo;
  
   }

printf("___________________________________________________________\n");
printf("Imprimindo função novamente após eliminar o último nodo:\n");
	
		imprime_lista_inicio(nodoini);	
		
		
nodoaux = (Nodo*) malloc(sizeof(Nodo));//questão 9
if (nodoaux)
{

	(*nodoaux).valor = 88;
	(*nodofim).proximo = nodoaux;
	nodofim = nodoaux;
	(*nodofim).proximo = NULL;
}		
		
printf("___________________________________________________________\n");
printf("Imprimindo função novamente após inserção de novo nodo no final:\n");

imprime_lista_inicio(nodoini);	
	
	
nodoaux = (Nodo*) malloc(sizeof(Nodo));//questão 10
if (nodoaux)
{
	
	(*nodoaux).valor = 55;

	
	(*nodoaux).proximo = (*(*nodoini).proximo).proximo; //ponteiro de ponteiro para ligar a struct que guarda 55 com a que guarda 6
	(*(*nodoini).proximo).proximo = nodoaux;//ponteiro de ponteiro para ligar a struct que guarda 5 com a que guarda 55

}
		
printf("___________________________________________________________\n");
printf("Imprimindo função novamente após inserção de novo nodo no terceiro lugar:\n");		
imprime_lista_inicio(nodoini);	

nodoaux = (Nodo*) malloc (sizeof(Nodo));
if (nodoaux)
{
	(*nodoaux).valor = 66;
	(*nodoaux).proximo = (*(*(*(*nodoini).proximo).proximo).proximo).proximo;//ponteiro de ponteiro de ponteiro de ponteiro....
	(*(*(*(*nodoini).proximo).proximo).proximo).proximo = nodoaux;	
	
}

printf("___________________________________________________________\n");
printf("Imprimindo função novamente após inserção de novo nodo no quarto lugar:\n");		
imprime_lista_inicio(nodoini);	




(*(*nodoini).proximo).proximo = (*(*(*nodoini).proximo).proximo).proximo;


printf("___________________________________________________________\n");
printf("Imprimindo função novamente após remover o nodo que quarda 55:\n");
imprime_lista_inicio(nodoini);	


	return 0;
}
