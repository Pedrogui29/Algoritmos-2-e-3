#include <iostream>

using namespace std;

int hash_aux(int k, int m)
{
	return k % m;
}

int main()
{
	int key, x;
	int h;

	cin >> key >> x;
	while(key != 0 && x != 0)
	{

		h = hash_aux(key, x);

		if(h < 0)
			h += x;

		cout << h << endl;


		cin >> key >> x;
	}		

		return 0;
	}