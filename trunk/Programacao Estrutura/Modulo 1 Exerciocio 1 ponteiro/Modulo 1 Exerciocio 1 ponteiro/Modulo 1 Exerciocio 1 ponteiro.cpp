// Modulo 1 Exerciocio 1 ponteiro.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

typedef struct aluno{
	char Nome[80];
	char RA[79];
	float Nota[2];
	float Media;
}aluno;

void aloca (aluno **p, int qtde);
void cadastro(aluno *p);
int busca(aluno *p, int qtde);
void controleDeNotas(aluno *p, int op); 


int _tmain(int argc, _TCHAR* argv[])
{
	aluno *Alu = NULL;
	int op, cont = 0, ind;

	do{
		system("cls");
		printf("=================\nDigite a opcao:\n=================\n[0] - Sair\n[1] - Cadast\n[2] - Cpntrole de Notas\n\n:: "); 
		scanf("%i",&op);fflush(stdin);

		switch(op)
		{	  
			case 1:
				{
					aloca (&Alu,cont+1);
					cadastro(Alu+cont);
					cont++;
					break;
				}
			case 2:
				{
					ind = busca(Alu, cont);
					if (ind==-1)
					{
						printf("\nAluno inexistente");
						system("pause");
					}
					break;
					
				}
		}

		}while(op != 0);
	return 0;
}

void aloca (aluno **p, int qtde)
{
	if((*p=(aluno*)realloc(*p,(qtde+1)*sizeof(aluno)))==NULL)
	{
		printf("erro de alocacao");
		exit(0);
	}
}

void cadastro(aluno *p)
{
	static int regitro = 1000;

	printf("\nDigite seu nome\n");
	gets(p->Nome); fflush(stdin); // *(p).nome
	printf("\nRA: ");
	gets(p->RA); fflush(stdin);
	for (int i = 0 ; i<2;i++)
	{
		*(p->Nota+i) = 0;
	}
	p->Media = 0;

	printf("\nCadastro efetuado com sucesso!!!\n\n\:");
	system("pause");
}

int busca(aluno *p, int qtde)
{
	char aux[7];

	printf("\n\nRA?: ");
	gets(aux); fflush(stdin);

	for (int i = 0 ; i < qtde; i++)
	{
		if(strcmp((p+i)->RA, aux) ==0)
		{
			return i;
		}
	}
	return -1;
}

void controleDeNotas(aluno *p, int op)
{
	printf("\n\nNome: %s\n",p->Nome);
	printf("\n\nRA: %s\n",p->RA);
	for(int i=0 ; i<2;i++)
	{
		do{
			printf("Nota %i: ",i+1);
			scanf("%f",p->Nota+1); fflush(stdin);
		}while(*(p->Nota+i) <= 0 || *(p->Nota+i) >= 10);
		p->Media+=*(p->Nota+i);
	}
	p->Media/=2;

	for(int i=0 ; i<2;i++)
	{
		printf("\nNota %i: %.2f",i+1,*(p->Nota+i));
		printf("\nMedia: %.2f\n\n\n\a",p->Media);
		system("pause");
	}

}