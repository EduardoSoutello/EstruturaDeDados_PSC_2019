/*
Fa�a um programa que cadastre o nome e o sal�rio de N funcion�rios,
onde N � uma quantidade escolhida pelo usu�rio.
Liste todos os funcion�rios e seus respectivos sal�rios ordenados
de acordo com o que � pedido nos itens abaixo.
IMPLEMENTA��O COM INSERTION SORT.

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
	int i, j, eleitoS;
	char c;
	char eleitoN[TAMANHONOME];
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

	//INSERTION SORT
	for (i = 1; i < TAMANHOVETOR ; i++) //la�o inicia na 2� posi��o at� a �ltima
	{
		eleitoS = Funcionario[i].Salario;
		strcpy_s(eleitoN,Funcionario[i].Nome);
		j = i - 1;

		while ((j >= 0) && (Funcionario[j].Salario > eleitoS)) //la�o que percorre os elementos a esquerda do numero eleito e reordena
		{
			Funcionario[j + 1].Salario = Funcionario[j].Salario;
			strcpy_s(Funcionario[j + 1].Nome, Funcionario[j].Nome);
			j = j - 1;
		}
		Funcionario[j + 1].Salario = eleitoS;
		strcpy_s(Funcionario[j + 1].Nome, eleitoN);
	}

	//IMPRESS�O DE RESULTADOS
	for (i = 0; i < TAMANHOVETOR; i++)
		printf("Funcionario %d, com nome %s e salario %d. \n", i + 1, Funcionario[i].Nome, Funcionario[i].Salario);

	printf("\n");
	system("pause");
	return 0;
}