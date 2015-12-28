#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define NQ 15

typedef struct hospede{
	int quarto;
	char nome[80];
	int acompanhante;
	char categoria;
	int dias;
}hospede;

typedef struct quarto{
	int num;
	char categoria;
	char status;
}quarto;

void aloca_quarto(quarto **q,int qtde);
void cadastro_quarto(quarto *q,int qtde);
void check_out(hospede *h,quarto *q);
void cadastro_hospede(hospede *h,quarto  *q);
int busca_quarto(quarto *q,char cat);
int busca_Vaga(hospede *h, int qtde, int numq);
void aloca_hospede(hospede **h, int qtde);

int _tmain(int argc, _TCHAR* argv[])
{
	{
	quarto *q=NULL;
	hospede *h=NULL;
	int cont=0,op,index = -1,numq;
	aloca_quarto(&q,NQ);
	cadastro_quarto(q,NQ);

	do
	{
		system("cls");
		printf("\n[1] Check-in \n[2] Check-Out \n[3] Sair");
		scanf("%i",&op);
		fflush(stdin);
		switch(op)
		{
			case 1:
				index = busca_Vaga(h,cont,-1);
				if(index== -1)
				{
					index = cont;
					aloca_hospede(&h,cont+1);
					cont++;
				}
				cadastro_hospede(h+index,q);
				break;
			case 2:
				printf("Numero do quarto: ");
				scanf("%i",&numq);
				fflush(stdin);
				index = busca_Vaga(h,cont,numq);
				if(index == -1)
				{
					printf("Quarto invalido!!!!!!!!");
				}
				else
				{
					check_out(h+index,q);
				}
				break;

			case 3:
				exit(1);
				break;
		}
	}
	while(1);

	return 0;
	}
}
void aloca_quarto(quarto **q,int qtde)
{
	if((*q=(quarto*)realloc(*q,qtde*sizeof(quarto)))==NULL)
	{
		printf("\nErro\n");
		exit(1);
	}
}//aloca_quarto

void cadastro_quarto(quarto *q,int qtde)
{
	int i,n=100;
	for(i=0;i<qtde;i++)
	{
		(q+i)->num=n++;
		(q+i)->status='L';
		if(i<5)
		{
			(q+i)->categoria='S';
		}
		else
		{
			(q+i)->categoria='F';
		}
	}
}//cadastro_quarto

int busca_Vaga(hospede *h, int qtde, int numq)
{
	int  i;
	for(i = 0 ; i < qtde;i++)
	{
		if((h+i)->quarto == numq)
		{
			return i;
		}
	}
	return -1;
}

void aloca_hospede(hospede **h, int qtde)
{
	if((*h=(hospede*)realloc(*h,qtde*sizeof(hospede)))==NULL)
	{
		printf("\nErro\n");
		exit(1);
	}
}

void cadastro_hospede(hospede *h,quarto  *q)
{
	printf("Fulaninho qual e o seu nome: ");
	gets(h->nome);
	fflush(stdin);
	printf("\nNumero de acompanhantes: ");
	scanf("%i",&(h->acompanhante));
	fflush(stdin);
	if(h->acompanhante == 0)
		h->categoria = 'S';
	else
		h->categoria = 'F';
	printf("\nQuantos Dias: ");
	scanf("%i",&(h->dias));
	fflush(stdin);

	h->quarto = busca_quarto(q,h->categoria);
	if(h->quarto == -1)
	{
		printf("Não ha quartos disponiveis");
	}
	else
	{
		printf("Cadastro realizado com sucesso");
	}

}

int busca_quarto(quarto *q,char cat)
{
	int i;
	for(i=0;i < NQ; i++)
	{
		if((q+i)->categoria == cat && (q+i)->status == 'L')
		{
			(q+i)->status = 'O';
			return((q+i)->num);
		}
	}
	return -1;
}

void check_out(hospede *h,quarto *q)
{

}
