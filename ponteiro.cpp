#include<iostream>

using namespace std;

int main()
{
	int *vetor = NULL; // armazena os dados
	int tam; // tamanho desejado para o vetor
	int i; // contador
	int *p; // ponteiro aux para leitura e escrita
	// Ler o tamanho desejado para o vetor
	cout << "Qual o tamanho desejado?" << endl;
	cin >> tam;
	// Alocar memoria para o vetor
	vetor = new int [tam];
	// Preencher o vetor
	p = vetor;
	for(i = 0; i < tam; i++)
	{
		cin >> *p;
		p++;
	}
	// Mostrar o vetor    p = vetor;
	for(i = 0; i < tam; i++)
	{
		cout << *p << " ";
		p++;
	}
	cout << endl;
	// Liberar a memoria usada pelo vetor    delete [] vetor;
	return 0;
}
