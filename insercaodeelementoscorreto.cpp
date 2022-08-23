#include <iostream>

using namespace std;

struct dado
{
	int status; //0 p/ vazio, 1 p/ ocupado
	int k; //chave
};

int hash_aux(int k, int m)
{
	return k % m;
}

int hash1(int k, int i, int m)
{
	return (hash_aux(k, m) + i) % m;
}

int hash_insert(dado T[], int m, int k)
{
	int i = 0;
	int j = 0;
	do
	{
		j = hash1(k, i, m);
		if(T[j].status != 1)
		{
			T[j].k = k;
			T[j].status = 1;
			return j;
		}
		else
			i++;
	}
	while(i != m);
	return -1; //tabela toda cheia
}

int main()
{
	dado T[100]; //tabela hash
	int tamanho;
	int i;
	int chaves;

	//leitura da tabela
	cin >> tamanho;

	//inicialização a tabela
	for(i = 0; i < tamanho; i++)
	{
		T[i].status = 0;
		T[i].k = -1;
	}

	//ler as chaves realizando a inseção na tabela
	cin >> chaves;
	while(chaves != 0)
	{
		hash_insert(T, tamanho, chaves);
		cin >> chaves;
	}

	//mostrando a tabela
	for(i = 0; i < tamanho; i++){
		cout << T[i].k;
		if(i<tamanho-1)
			cout << " ";
	}

	cout << endl;
}