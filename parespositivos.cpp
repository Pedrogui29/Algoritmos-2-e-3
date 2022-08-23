#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

	int *vetor = NULL;
	int tamanho;
	int i;
	int parespositivos = 0;


	//ler tamanho
	cin >> tamanho;

	//alocar memoria para um vetor
	vetor = new int [tamanho];
	//preencher vetor
	for(i = 0; i < tamanho; i++)
	{
		cin >> vetor[i];
	}
	
	//mostrar vetor
	for(i = 0; i < tamanho; i++)
	{
		if((vetor[i] > 0 )& (vetor[i] % 2 == 0))
		{
			parespositivos++;
		}
	}

	cout << parespositivos;
	//liberar a memoria usada pelo vetor
	delete[]vetor;

	return 0;
}
