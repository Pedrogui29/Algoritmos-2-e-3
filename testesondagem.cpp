#include <iostream>

using namespace std;

// Struct dado para a chave e status da tabela
struct dado 
{
	int k;      // chave
	int status; // 0 = vazio e 1 = ocupado
};

// Função do hash auxiliar
int hash_aux(int k, int m)
{
	int j;
	j =  k % m;
	if(j < 0)
		j += m;
	return j;
}

// Função hash1 com sondagem quadratica
int hash1(int k, int i, int m, int c1, int c2)
{

	return (hash_aux(k, m) + (c1 * i) + (c2 * (i * i))) % m;
}

//Função hash para inserir elementos
int hash_insert(dado tabela[], int m, int k, int c1, int c2) 
{
	int i = 0;
	int j;

	do
	{
		j = hash1(k, i, m, c1, c2);

		if (tabela[j].status != 1)
		{
			tabela[j].k = k;
			tabela[j].status = 1;
			return j;
		}
		else
			i = i + 1;
	}
	while (i != m);
	return -1;
}

int main()
{
	dado tabela[20]; // tabela hash
	int key;      //chave
	int m;      //tamanho da tabela
	int c1;     // c1
	int c2;     // c2
	int i;   //aux

	//Inserindo o tamanho da tabela e valores de c1 e c2
	cin >> m;
	cin >> c1;
	cin >> c2;

	// Inicializando a tabela
	for (int j = 0; j < m; j++)
	{
		tabela[j].k = -1;

		tabela[j].status = 0;
	}

	//leitura da chave
	cin >> key;
	while (key != -1)
	{
		hash_insert(tabela, m, key, c1, c2);
		cin >> key;
	}

   // Mostrando a tabela preenchida  
	for (i = 0; i < m; i++)
	{
		
		cout << tabela[i].k << " ";
	}

	cout << endl;

	return 0;
}
