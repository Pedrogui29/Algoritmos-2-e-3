#include <iostream>
using namespace std;

struct dado
{
	int k;
	int status;

};

int h1(int k, int m)
{
	int H1;

	H1 = k % m;

	if(H1 < 0)
		H1 = H1 + m;

	return 	H1;
}



int h2(int k, int m)
{
	int H2;

	H2 = 1 + (k % (m - 1));

	if(H2 < 0)
		H2 = H2 + m;

	return H2;
}
int hash1(int k, int m, int i)
{

	return(h1(k, m) + (i * h2(k, m))) % m;


}

int hash_insert(dado t[], int m, int k)
{
	int i, j;
	i = 0;
	do
	{

		j = hash1(k, m, i);
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
		j = hash1(k, m,i);
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
	}// consegui remover
	else
		return -1; // k nao esta na tabela
}


int main()
{

	int tam;//tamanho
	int i;//auxiliar
	int num;//]numero inserido
	dado T[20];
	int codigo;
	int j = 0;
	int pesquisa;
	int removido;
	int saida;


	//let tamanhoda tabela
	cin >> tam;

	for(i = 0; i < tam; i++)
	{
		T[i].k = -1;
		T[i].status = 0;
	}

	cin >> codigo;

	while(codigo != 5)
	{
		
		if(codigo==1){
			cin >> num;
				hash_insert(T, tam, num);
		}

		else if(codigo==2){
			cin >> num;
			pesquisa = hash_search(T, tam, num);
			cout << pesquisa;
			cout << endl;
		}

		else if(codigo==3){
			cin >> num;
			hash_remove(T, tam, num);
		}
		else if(codigo==4){
			for(i = 0; i < tam; i++)
			{
				saida = hash1(num, tam, i);

				cout << T[i].k << " ";
         
			}
			cout << endl;
		}
		
		cin >> codigo;}




	return 0;
}

