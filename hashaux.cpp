#include <iostream>

using namespace std;


int hash_aux(int k, int m)
{
	int j;
	j =  k % m;
	if (j < 0)
		j += m;
	return j;
}


int main()
{
	int k; //chave
	int m; //tamanho
	int res; //resultado


	cin >> k;
	cin >> m;


	while (k != 0 && m != 0)
	{

		res = hash_aux(k, m);

		cout << res << endl;


		cin >> k;
		cin >> m;
	}

	return 0;
}
