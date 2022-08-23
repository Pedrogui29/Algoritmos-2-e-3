#include<iostream>
#include<iomanip>

using namespace std;

struct dado
{
	float nota1;
	float nota2;
	float nota3;
	float nota4;
};
int main()
{
	dado *ficha; // ponteiro para uma struct dado
	int alunos; // tamanho desejado para o vetor
	int i; // contador
	float soma = 0;
	float media = 0;

	// Ler o tamanho desejado para o vetor
	cin >> alunos;

	// Alocar memória para o vetor
	ficha = new dado[alunos];

	// Ler os elementos do vetor
	for(i = 0; i < alunos; i++)
	{
		cin >> ficha[i].nota1;
		cin >> ficha[i].nota2;
		cin >> ficha[i].nota3;
		cin >> ficha[i].nota4;
		soma = soma +  ficha[i].nota1 +  ficha[i].nota2 +  ficha[i].nota3 +  ficha[i].nota4;
	}

	media = (soma / alunos);
	// Mostrando media
	cout << fixed << setprecision(2) << media << endl;

	// Liberar memória alocada para o vetor
	delete [] ficha;
	return 0;
}
