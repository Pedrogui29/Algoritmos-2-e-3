#include <iostream>
using namespace std;

struct dado
{
	int k;
	int status;

};

int hash_aux(int k, int m)
{
	int h;

	h = k % m;

	if(h < 0)
		h = h + m;

	return h;
}

int hash1(int k, int i, int m)
{
	return (hash_aux(k, m) + i) % m;
}

int hash_insert(dado t[], int m, int k)
{
	int i, j;
	i = 0;
	do
	{

		j = hash1(k, i, m);
		if (t[j].status != 1)
		{
			t[j].k = k;
			t[j].status = 1;
			return j;
		}
		else
			i = i + 1;
	}
	while (i != m);
	return -1;
}

int hash_search(dado T[], int m, int k)
{

	int i = 0;
	int j;
	do
	{
		j = hash1(k, i, m);
		if (T[j].k == k)
			return j;
		i = i + 1;
	}
	while (T[j].status != 0 or i < m);
	return -1;

}

int hash_remove(dado t[], int m, int k)
{

	int j;
	j = hash_search(t, m, k);
	if(j != -1)
	{
		t[j].status = 2;
		t[j].k = -1;
		return 0;
	}

	else
	{
		return -1;
	}
}

int main()
{

	int tamanho;
	int aux;
	dado T[20]; //vetor 
	int num;//numero inserido
	int pesquisa;

	//Realizando leitura do tamanho da tabela
	
	cin >> tamanho;
	
	//Realizando inicialização da tabela
	for(aux = 0; aux < tamanho; aux++)
	{
		T[aux].k = -1;
		T[aux].status = 0;
	}

	//leitura das chaves e inserção na tabela
	cin >> num;
	while(num != 0)
	{

		hash_insert(T, tamanho, num);
		cin >> num;
	}

	//Inserido numero de pesquisa para remoção

	cin >> pesquisa;
	
  // Chamada da função de remoção
	hash_remove(T, tamanho, pesquisa);

	//MOstrando tabela sem o numero removido
	for(aux = 0; aux < tamanho; aux++)
		cout << T[aux].k << " " ;


	return 0;
}
