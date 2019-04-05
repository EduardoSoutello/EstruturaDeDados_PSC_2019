/*
Fa�a um programa que cadastre o nome e o sal�rio de N funcion�rios,
onde N � uma quantidade escolhida pelo usu�rio.
Liste todos os funcion�rios e seus respectivos sal�rios ordenados
de acordo com o que � pedido nos itens abaixo.
IMPLEMENTA��O COM SELECTION SORT.

Ordene por ordem crescente de sal�rio;

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHOVETOR 5
#define TAMANHONOME  30

int main()
{
	struct CadastroFuncionario
	{
		char Nome[TAMANHONOME];
		int Salario;
	};

	int vet[TAMANHOVETOR] = { 0 };
	int i, j, pos, eleitoS, Menor;
	char c;
	char eleitoN[TAMANHONOME], MenorN[TAMANHONOME];
	CadastroFuncionario Funcionario[TAMANHOVETOR];

	//INSER��O DE DADOS
	for (i = 0; i < TAMANHOVETOR; i++)
	{
		printf("Digite o nome do funcionario %d: ", i + 1);
		gets_s(Funcionario[i].Nome);
		printf("\n");

		printf("Digite o salario do funcionario %d: ", i + 1);
		scanf_s("%d", &Funcionario[i].Salario);
		printf("\n");
		while ((c = getchar()) != '\n' && c != EOF) {} //limpa buffer teclado
	}

	//SELECTION SORT
	for (i = 0; i < (TAMANHOVETOR - 1); i++) //la�o da primeira at� a penultima posi��o
	{
		eleitoS = Funcionario[i].Salario;
		strcpy_s(eleitoN, Funcionario[i].Nome);

		Menor = Funcionario[i + 1].Salario; //encontrar o menor valor a direito do eleito
		strcpy_s(MenorN, Funcionario[i + 1].Nome);
		pos = i + 1;

		for (j = i + 2; j < TAMANHOVETOR;j++)//la�o para encontrar o menor valor � direita
		{
			if (Funcionario[j].Salario < Menor)
			{
				Menor = Funcionario[j].Salario;
				strcpy_s(MenorN, Funcionario[j].Nome);
				pos = j;
			}
		}

		//testa se troca o menor com o eleito
		if (Menor < eleitoS)
		{
			Funcionario[i].Salario = Funcionario[pos].Salario;
			Funcionario[pos].Salario = eleitoS;

			strcpy_s(Funcionario[i].Nome, Funcionario[pos].Nome);
			strcpy_s(Funcionario[pos].Nome, eleitoN);
		}
	}

	//IMPRESS�O DE RESULTADOS
	for (i = 0; i < TAMANHOVETOR; i++)
		printf("Funcionario %d, com nome %s e salario %d. \n", i + 1, Funcionario[i].Nome, Funcionario[i].Salario);

	printf("\n");
	system("pause");
	return 0;
}