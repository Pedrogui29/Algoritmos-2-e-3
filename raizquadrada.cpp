#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int raiz(int x, int x0, int e)
{
	int dobro;
	dobro = 2 * x0;
	int pot;
	pot = pow(x0, 2);

	if((pow(x0, 2) - x) <= e)
		return x0;

	else
		return raiz(x, (pot + x) / dobro, e);
}

int main()
{

	int x;
	int xo;
	int e;
	float resultado;

	cin >> x;
	cin >> xo;
	cin >> e;

	resultado = raiz(x, xo, e);

	cout << fixed << setprecision(2);
	cout << resultado << endl;




	return 0;
}
