#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Inserir Inicio
// Imprimir da esquerda para direita
// Imprimir da direita para esquerda
// Inserir no final
// Buscar no elemento e retornar o ponteiro para o elemento ou null caso não encontre
// Função que remove o ultimo elemento
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
	printf("4) Inserir no final\n");
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

//2
void imprimir(struct no *lista){
	struct no *p;
	p = lista;
		
	while(p != NULL){
		printf("%d \n",p->info);
		p=p->dir;
	}
	getch();
} 

//3
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

// - 4
void inserir_final(struct no **lista){
	int x = 0;
	printf("Insira o valor:");
	scanf("%d",&x);
		
	struct no *p;
	struct no *q;
	struct no *r;
	q = *lista;

	if((p=malloc(sizeof(struct no))) == NULL || (r=malloc(sizeof(struct no))) == NULL){
		printf("Erro na alocação de memória");
	}
	else{
		
		while(q != NULL){
			if(q->esq == NULL){
				p = q;
			}
			q = q->esq;
		}
		r->info = x;
		r->esq = q;
		r->dir = NULL;

		*lista= p;
	}
	
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
