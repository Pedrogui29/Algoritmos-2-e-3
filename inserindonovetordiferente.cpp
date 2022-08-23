#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

	int *vetor = NULL;
	
	int i;//contador

        int tamanho;//tamanho


	
	cin >> tamanho;//declarar tamanho
	vetor = new int [tamanho];//alocar memoria
	for(i = 0; i < tamanho; i++)//atribuir valores para o vetor
	{
		cin >> vetor[i];
        }

	for(i = 0; i < tamanho; i++)
	{
		cout << vetor[i] << " " ;//mostrar o vetor
	}
	delete[]vetor;//liberar a memoria

	return 0;
}