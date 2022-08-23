#include <iostream>
using namespace std;

int comb(int n, int k)
{
	int res;

	if(k == 1)
	{
		return n;
	}
		   else if(k == n)
	{
		return 1;
	}
	else
	{
	res =  comb(n - 1, k - 1) + comb(n - 1, k);
	  return res;
	}
}
int main()
{

	int n;
	int k;

	cin >> n;
	cin >> k;

	cout << comb(n, k) << endl;



	return 0 ;
}
