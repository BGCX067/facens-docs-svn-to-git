// Modulo 1 Exercicio 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct cliente {
	char nome[30];
	int conta;
	float saldo;
				};

cliente cadastro ();
cliente movimenta (cliente AUX, int op);

void _tmain(int argc, _TCHAR* argv[])
{
	cliente cli [10];
	int cont=0, op, conta, i, achou, cconta;

	do{
		system("cls");
		printf("Digite a opcao: \n[0] - Sair \n[1] - Cadastrar \n[2] - Deposito \n[3] - Reirada\n\n");
		scanf("%i", &op); fflush(stdin);

		switch(op)
		{

		case 1:
			{
				if (cont > 9)
				{
					exit(1);
				}
				else 
				{
					cli[cont] = cadastro();
				}
			}
		case 3:
			{
				printf("\nConta corrente");
				scanf("&i", &conta); fflush(stdin);
				achou = 0;
				for (i = 0 ; i < cont ; i++)
				{
					if (cli[i].conta == conta)
					{
						achou = 1;
						i = cont;
					}
					if (achou == 0) 
					{
						printf("");
					}
					else
					{
						cli[cconta] = movimenta(cli[cconta],op);
					}
				}
			}
			break;
		}

	}while(!(op == 0));
}

cliente cadastro()
{
	static int reg = 1;
	cliente aux;

	printf("\nNome: ");
	gets(aux.nome);
	aux.conta = reg++;
	aux.saldo = 0;

	return aux;
}

cliente movimenta (cliente AUX, int op)
{
	float quantia;
	printf("\nNome: %s", AUX.nome);
	printf("\nSaldo atual: %.2f\n",AUX.saldo);
	printf("\nQuantia a ser despitada / retirada: ");
	scanf("%f", &quantia); fflush(stdin);

	if (op == 2)
	{
		AUX.saldo += quantia;
	}
	else
	{
		AUX.saldo -= quantia;
		printf("\nSaldo insuficiente\n");
	}

	printf ("\n\n\nSaldo atual: %.2f", AUX.saldo);
	return AUX;

}