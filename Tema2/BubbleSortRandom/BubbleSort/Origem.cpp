/*
Implementar um BUBBLE SORT crescente com valores de entrada aleatorios.

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHOVETOR 10

int main()
{
	int vet[TAMANHOVETOR] = { 0 };
	int i, n, aux;
	srand(time(NULL));

	//INSER��O DE DADOS
	for (int i = 0; i < TAMANHOVETOR; i++)
		vet[i] = rand() % 100;

	printf("VETOR NAO ORDENADO:\n");
	for (int i = 0; i < TAMANHOVETOR; i++) //IMPRIME N�O ORDENADO
		printf("%d\n", vet[i]);

	//BUBBLE SORT
	for (n = 1; n <= TAMANHOVETOR; n++) //La�o para o tamanho do vetor
	{
		for (i = 0; i < (TAMANHOVETOR - 1); i++) //La�o da 1� at� a penultima posi��o
		{
			if (vet[i] > vet[i+1])
			{
				aux = vet[i];
				vet[i] = vet[i + 1];
				vet[i + 1] = aux;
			}

		}

	}

	//IMPRESS�O DE RESULTADOS
	printf("VETOR ORDENADO:\n");
	for (int i = 0; i < TAMANHOVETOR; i++) //IMPRIME ORDENADO
		printf("%d\n", vet[i]);


	printf("\n");
	system("pause");
	return 0;
}