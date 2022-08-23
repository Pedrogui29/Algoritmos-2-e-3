#include <iostream>

using namespace std;

int main()
{

	int *vetor = NULL;
	int tamanho;
	int i;


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
		cout << vetor[i] << " " ;
	}
	//liberar a memoria usada pelo vetor
	delete[]vetor;

	return 0;
}
