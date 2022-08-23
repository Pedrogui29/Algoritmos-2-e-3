#include <iostream>
using namespace std;

// Função recursiva que implementa a potencia
int elevar(int k, int n)
{
	
	if(n == 0)
	{
		return 1;
	}
	else
	{
		
		return k * elevar(k, n - 1);
	}
}
int main()
{

	int k; //Base
	int n; // Expoente

	// Inserindo valores de k, n (Base, expoente)
	cin >> k;
	cin >> n;

	// Mostrando resultado com a chamada da função recursiva
	cout << elevar(k, n) << endl;



	return 0 ;
}
