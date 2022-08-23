#include <iostream>
using namespace std;

void bubbleSort(int vetor[], int tamanho)
{
	int i, j; // contadores
	int trab;
	bool troca;
	int limite;
	troca = true;
	limite = tamanho - 1;
	while (troca)
	{
		troca = false;
		for (i = 0; i < limite; i++)
			if (vetor[i] > vetor[i + 1])
			{
				trab = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = trab;
				j = i;
				troca = true;
			}
		limite = j;
	}
}


int main()
{
	int vetor[10];
	int n;
	int i;
	int x;

	cin >> x;
	i = 0 ;
	while(x != -1)
	{
		vetor[i] = x;
		i ++;
		cin >> x;
	}
	n = i;

	bubbleSort(vetor, n);


	for(i = 0; i < n; i++)
	{
		cout << vetor[i] << " ";


	}
	cout << endl;
	return 0;
}
