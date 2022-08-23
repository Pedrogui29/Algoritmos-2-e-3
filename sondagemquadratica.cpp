#include <iostream>
#include <cmath>

using namespace std;

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

int main()
{
	int k, m, c1, c2;
	int j;
	int vetor[100];

	cin >> k;
	cin >> m;
	cin >> c1;
	cin >> c2;

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
