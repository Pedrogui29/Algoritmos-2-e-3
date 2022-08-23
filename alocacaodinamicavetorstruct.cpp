#include<iostream>
using namespace std;
struct dado
{
	int codigo;
	float preco;
};
int main()
{
	dado *produto; // ponteiro para uma struct dado
	int tam; // tamanho desejado para o vetor
	int i; // contador

	// Ler o tamanho desejado para o vetor
	cin >> tam;

	// Alocar memória para o vetor
	produto = new dado[tam];

	// Ler os elementos do vetor
	for(i = 0; i < tam; i++)
	{
		cin >> produto[i].codigo;
		cin >> produto[i].preco;
	}
	cout << "Saudades codar em c++" << endl;
	// Mostrar o vetor
	for(i = 0; i < tam; i++)
	{
		cout << produto[i].codigo << " ";
		cout << produto[i].preco << endl;
	}

	// Liberar memória alocada para o vetor
	delete [] produto;
	return 0;
}
