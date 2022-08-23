#include <iostream>
using namespace std;


int h1(int k, int m)
{
	int j;

	j = k % m;

	if(j < 0)
		j = j + m;

	return 	j;
}



int h2(int k, int m)
{
	int j;

	j = 1 + (k % (m - 1));

	if(j < 0)
		j = j + m;

	return j;
}
int hash1(int k, int i, int m)
{

	return(h1(k, m) + i * h2(k, m)) % m;


}

int main()
{

	int tamanho;// tamanho
	int i;//auxiliar
	int numero;//numero inserido
	int res; // resultado



	cin >> numero;
	cin >> tamanho;

	for(i = 0; i < tamanho; i++)
	{
		res = hash1(numero, i, tamanho);

		cout << res << " ";
	}
	cout << endl;

	return 0;
}

