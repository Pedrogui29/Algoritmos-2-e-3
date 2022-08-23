#include <iostream>
#include <iomanip>

using namespace std;

int acimaMedia(int *vetor, int N)   {
	
	float media = 0;
	float resultado = 0;
	int aux = 0; 
	int i = 0;
	
		for(i = 0; i < N; i++)
	{
		media =  vetor[i] + media;
	}
	
	resultado = (media/N);
	
		for(i = 0; i < N; i++)
	{
		if(vetor[i] > resultado){
			aux++;
		}
	}
	return aux;
}

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

	cout << acimaMedia(vetor, tamanho) << " elementos acima da media" << endl;
	
	//liberar a memoria usada pelo vetor
	delete[]vetor;

	return 0;
}
