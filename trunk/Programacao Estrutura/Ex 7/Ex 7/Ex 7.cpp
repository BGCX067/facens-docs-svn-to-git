// Ex 7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QC 7;
typedef struct aluno{
        char *nome;
        char *curso;
        }aluno;

void aloca_struct(aluno **a,int qtde);
void cadastro(aluno *a,int q, char **l);
void cadastro_curso(char **l);
void aloca_string(char **p,int tam);
int busca_string(aluno *a,int q,char *aux);
int busca_lista(char **lista,char *aux);
void mostra(aluno *a,int qtde);
void mostra_endereco(aluno *a,int qtde);
void maiuscula(char *p);

int _tmain(int argc, _TCHAR* argv[])
{
	aluno *al=NULL;  //ponteiro p/estrutura
	int cont=0,op;
	char *lista[7]; //matriz de ponteiro

	cadastro_curso(lista);

	do{
		system("cls");
		printf("\n[1] Cadastro\n[2] Mostra\n[3] Mostra Endereco\n[4] Fim\nOpcao: ");
		scanf("%i",&op);
		fflush(stdin);
	switch(op)    
	{
	case 1:
		{
			aloca_struct(&al,cont+1);
			cadastro(al,cont,lista);
			cont++;
			break;
		}
    case 2: 
		{
			mostra(al,cont);
            break;
		}
    case 3: mostra_endereco(al,cont);
            break;
    }
  }while(op!=4);
	return 0;
}


void aloca_struct(aluno **a,int qtde)
{
if((*a=(aluno*)realloc(*a,qtde*sizeof(aluno)))==NULL)
  {
  printf("\nErro Estrutura\n\n");
  exit(1);
  }
}

void aloca_string(char **p,int tam)
{
if((*p=(char*)realloc(*p,tam*sizeof(char)))==NULL)
  {
  printf("\nErro\n\n");
  exit(1);
  }
}

void cadastro(aluno *a,int q, char **l)
{
	char aux[20];
	int ind;
	(a+q)->nome=NULL;
	(a+q)->curso=NULL;

	//NOME
	printf("\nNome: ");
	gets(aux);
	fflush(stdin);
	maiuscula(aux);
	ind=busca_string(a,q,aux);
	if(ind==-1)
	{
		aloca_string(&((a+q)->nome),strlen(aux)+1);
		strcpy((a+q)->nome,aux);
	}
	else
	(a+q)->nome=(a+ind)->nome;   //recebe endereco do nome 
	//Curso
	printf("\nCurso: ");
	gets(aux);
	fflush(stdin);
	maiuscula(aux);
	ind = busca_lista(l, aux);
	if(ind==-1)
	{
		printf("\nCursao inexistente\n\n");
	}
	else
	{
		(a+q)->curso=*(l+ind);   //recebe endereco da lista
	}
}

int busca_string(aluno *a,int q,char *aux)
{
	int i;
	for(i=0;i<q;i++)
	{
		if(strcmp((a+i)->nome,aux)==0)
		{
			return i;
		}
		return -1;
	}
}

void mostra(aluno *a,int qtde)
{
int i;
for(i=0;i<qtde;i++)
  {
  printf("\nAluno %i",i+1);
  printf("\nNome : %s",(a+i)->nome);
  printf("\nCurso: %s\n",(a+i)->curso);
  }
system("pause");
}//mostra

void mostra_endereco(aluno *a,int qtde)
{
int i;
for(i=0;i<qtde;i++)
  {
  printf("\nAluno %i - Endereco:%u",i+1,(a+i));
  printf("\nEndereco: %u - Conteudo: %u - Nome :%s",&((a+i)->nome),(a+i)->nome,(a+i)->nome);
  printf("\nEndereco: %u - Conteudo: %u - Curso: %s\n",&((a+i)->curso),(a+i)->curso,(a+i)->curso);
  }
system("pause");
}

void maiuscula(char *p)
{
int i,tam;
tam=strlen(p);
for(i=0;i<=tam;i++)
  if(*(p+i)>='a'&& *(p+i) <= 'z')
    *(p+i)-=32;
}

void cadastro_curso(char **l)
{
	char aux[20];
	int i;

	printf("\n\nCadastro de curso");

	for ( i = 0 ; i < 7 ; i++)
	{
		printf("\nCurso: ");
		gets(aux);
		fflush(stdin);
		maiuscula(aux);
		*(l+i) = NULL;
		aloca_string((l+i) ,strlen(aux)+1);
		strcpy(*(l+i), aux);
	}

	for ( i = 0 ; i < 7 ; i++)
	{
		printf("\nEndereceo: %u - Conteudo: %u - Curso: %s\n",(l+i),*(l+i),*(l+i));	
	}
	system("pause");
}

int busca_lista(char **lista,char *aux)
{
	for(int i = 0 ; i < 7 ; i++)
	{
		if(strcmp(*(lista+i),aux)==0) //achou
		{
			return i;
		}
		return -1;
	}

}

