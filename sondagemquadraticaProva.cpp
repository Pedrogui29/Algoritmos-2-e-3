#include <iostream>
#include <cmath>

using namespace std;

struct dado
{
    int k;      // chave
    int status; // 0 = vazio e 1 = ocupado
};

int hash_aux(int k, int m)
{
	int j;
	j =  k % m;
	if(j < 0)
		j += m;
	return j;
}


int hash1(int k, int i, int m, int c1, int c2)
{

	return (hash_aux(k, m) + (c1 * i) + (c2 * (i * i))) % m;
}

int hash_insert(dado t[], int m, int k) //função hash para inserir elementos 
{
    int i = 0; 
    int j;
    int c1;
    int c2;

    do
    {
        j = hash1(k, j, m, c1, c2);

        if (t[j].status != 1)
        {
            t[j].k = k;
            t[j].status = 1;
            return j;
        }
        else
            i = i + 1;
    } while (i != m);
    return -1;
}

int main()
{
	dado tabela[20];
	int k;
	int m; 
	int c1;
	int c2;
	int j;
	int vetor[100];
	
	 //Inserir o tamanho da tabela
    cin >> m;

    // Inicialização da tabela
    for (int j = 0; j < m; j++)
    {
        tabela[j].k = -1;

        tabela[j].status = 0;
    }
    
	cin >> c1;
	cin >> c2;
	
	  //leitura da chave
    
    while (k != -1)
    {
        cin >> k;
    }
    
    // chamando função para mostrar na tabela 
    hash_insert(tabela, m, k);

	for(j = 0; j < m; j++)
		vetor[j] = hash1(k, j, m, c1, c2);

	for(j = 0; j < m; j++)
	{
		cout << vetor[j];
		if(j < m - 1)
			cout << " ";
	}

	cout << endl;



	return 0;
}
