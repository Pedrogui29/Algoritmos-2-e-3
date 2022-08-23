#include <iostream>
using namespace std;

void insercaoDireta(int vetor[], int tamanho)
{
	int i, j; // contadores
	int chave;
	for (j = 1; j < tamanho; j++)
	{
		chave = vetor[j];
		i = j - 1;
		while ((i >= 0) && (vetor[i] < chave))
		{
			vetor[i + 1] = vetor[i];
			i = i - 1;
		}
		vetor[i + 1] = chave;
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
	while(x != 0)
	{
		vetor[i] = x;
		i ++;
		cin >> x;
	}
	n = i;

	insercaoDireta(vetor, n);

	for(i = 0; i < n; i++)
	{
		cout << vetor[i] << " ";
		cout << endl;

	}

	return 0;
}
