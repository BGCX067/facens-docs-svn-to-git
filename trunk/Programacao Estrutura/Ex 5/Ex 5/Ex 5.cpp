// Ex 5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
	char *nome;
	char *curso;
}aluno;

void AlocaStruct ( aluno **a, int qtd);
void Cadastro(aluno *a);
void AlocaString(char **n, int tam);

int _tmain(int argc, _TCHAR* argv[])
{
	aluno *al = NULL; 
	int op,cont;

	do{
		system("cls");
		printf("[0] - Sair\n[1] - Cadastro\n[2] - Mostra\n::");
		scanf("%i",&op);

		switch(op)
		{
		case 1:
			{
				AlocaStruct(&al,cont+1);
				(al+cont)->curso =NULL;
				(al+cont)->nome  =NULL;
				Cadastro(al);
				break;
			}
		}
	}while(true);
	return 0;
}

void AlocaStruct ( aluno **a, int qtd)
{
	if ((*a=(aluno*)realloc(*a,qtd*sizeof(aluno)))==NULL)
	{
		printf("ERRO!!!");
		exit(1);
	}
}

void Cadastro(aluno *a)
{
	char aux[20];

	printf("\nNome: ");
	gets(aux);
	fflush(stdin);

	AlocaString(&(a->nome), strlen(aux));
	strcpy(a->nome ,aux);
	AlocaString(&(a->curso), strlen(aux));
	strcpy(a->curso ,aux);
}

void AlocaString(char **n, int tam)
{
	if ((*n = (char*)realloc(NULL,tam*sizeof(aluno)))==NULL)
	{
		printf("ERRO!!!");
		exit(1);
	}

}