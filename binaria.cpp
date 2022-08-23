#include <iostream>
#include <math.h>
using namespace std;


int binaria(int vetor[], int tamanho, int x)
{
	bool achou; // var aux p/ busca
	int baixo, meio, alto; // var aux
	int res;
	baixo = 0;
	alto = tamanho - 1;
	achou = false;
	while ((baixo <= alto) && (achou == false))
	{
		meio = (baixo + alto) / 2;
		if (x < vetor[meio])
			alto = meio - 1;
		else if (x > vetor[meio])
			baixo = meio + 1;
		else
			achou = true;
	}
	if (achou)
	{
		res = meio;
		return res;
	}
	else
	{
		res = -1;
		return res;
	}
}

int main()
{
	int vetor[10];
	int n;
	int i;
	int p;
	int x;
	int res;

	cin >> p;
	i = 0 ;
	while(p != -1)
	{
		vetor[i] = p;
		i ++;
		cin >> p;
	}
	n = i;
	cin >> x;

	res = binaria(vetor, n, x);

    if(res == -1)
	{
		cout << "Nao possui acesso"  << endl;
	}
	else
	{
		cout << "Possui acesso" << endl;
	}




	return 0;
}
