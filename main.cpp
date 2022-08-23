#include <iostream>
using namespace std;

int main()
{

	int i, j;
	int n;
	int x, y, z = 2;

	cin >> n;
	for(j = 0; j < n; j++)
	{
		i = 1;
		while(i < n)
		{
			y = 2 * i;
			x = y * z;
			cout << i << endl;
			i = i * 2;


		}
	}
	return 0;
}
