#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

struct dados
{
	int codigo; // codigo do produto
	int quantidade; // quantidade em estoque
	float preco; // preco unitario
};
dados produto[100];


void quickSort(dados vetor[], int tamanho, int i, int j)
{
	int esq, dir, pivo;
	dados trab;
	esq = i;
	dir = j;
	pivo = vetor[(int)round((esq + dir) / 2.0)].codigo;
	do
	{
		while (vetor[esq].codigo < pivo)
			esq++;
		while (vetor[dir].codigo > pivo)
			dir--;
		if (esq <= dir)
		{
			trab = vetor[esq];
			vetor[esq] = vetor[dir];
			vetor[dir] = trab;
			esq++;
			dir--;
		}
	}
	while (esq <= dir);
	if (dir - i >= 0)
	{
		quickSort(vetor, tamanho, i, dir);

	}
	if (j - esq >= 0)
	{
		quickSort(vetor, tamanho, esq, j);

	}
}


int main()
{
    
	int n; // tamanho do vetor 
	int i = 0; // contador 
	int j = 0; // numero buscado

	
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> produto[i].codigo;
		cin >> produto[i].quantidade;
		cin >> produto[i].preco;
	}

	quickSort(produto, n, 0,  n-1);
	
	
	for(int i = 0; i < n; i++)
	{
		cout << "Codigo: " << fixed << setprecision(2) << produto[i].codigo << endl;
		cout <<"Quantidade em estoque: " << fixed << setprecision(2) << produto[i].quantidade << endl;
		cout <<"Preco unitario: R$ " << fixed << setprecision(2) << produto[i].preco << endl;
		cout << endl;
	}



	return 0;
}
