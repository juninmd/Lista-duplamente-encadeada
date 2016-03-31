#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Inserir Inicio
// Imprimir da esquerda para direita
// Imprimir da direita para esquerda
struct no {
	int info;
	struct no *esq, *dir;
};

/*
 	Menu principal é responsável por printar
 	na tela, todas as opções disponíveis
*/
void menuPrincipal(){
	system("cls");
	printf("--- MALLOC REVERSE ---\n\n");
	printf("1) Inserir Inicio\n");
	printf("2) Listar\n");
	printf("3) Listar reverso\n");
	printf("\n9) Sair\n\n");
}

// - 1
void insere_inicio(struct no **lista){
	int x = 0;
	printf("Insira o valor:");
	scanf("%d",&x);
		
	struct no *p;

	if((p=malloc(sizeof(struct no))) == NULL){
		printf("Erro na alocação de memória");
	}
	else{
		p->info = x;
		p->dir = *lista;
		p->esq = NULL;
		
		if(*lista != NULL)
			(*lista)-> esq = p;
		
		*lista= p;
	}
	
}

void imprimir(struct no *lista){
	struct no *p;
	p = lista;
		
	while(p != NULL){
		printf("%d \n",p->info);
		p=p->dir;
	}
	getch();
} 

void imprimirReverso(struct no *lista){
	struct no *p,*q;
	p = lista;
		
	while(p != NULL){
			if(p->dir == NULL){
				q = p;
			}
			p=p->dir;
	}
	p=q;
	
	while(p != NULL){
		printf("%d \n",p->info);
		p=p->esq;
	}
	getch();
} 


int main(int argc, char *argv[]) {
setlocale(LC_ALL,"portuguese");
	int tecla = 0;
	struct no *lista;
	lista = NULL;
	
	do{
		menuPrincipal();
		printf("Insira a opcao ->");
		scanf("%d",&tecla);
		menuPrincipal();
		
		switch(tecla){
			case 1:{
				insere_inicio(&lista);
				break;
			}
			case 2:{
				imprimir(lista);
				break;
			}
			case 3:{
				imprimirReverso(lista);
				break;
			}
		}
	}while(tecla != 9);
   
}
