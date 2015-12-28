// yahoo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int vet[8] = {3, 2, 4, 1, 2, 5, 8, 3};
	int indice[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	int aux;

	for (int i = 7 ; i > 4 ; i--)
	{
		aux = vet[i];
		vet[i] = vet[7-i+1];
		vet[7-i+1] = aux;
	}

	vet[3] = vet[0];
	vet[vet[3]] = vet[vet[2]];

	vet;
	return 0;
}

