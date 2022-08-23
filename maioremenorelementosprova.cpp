#include <iostream>
#include <list>

using namespace std;

void maiorMenor(list<int> lista, int &menor, int &maior)
{


	list<int>::iterator p;
	for(p = lista.begin(); p != lista.end(); p++)
	{

		if(*p > maior)
		{
			maior = *p;
		}
		else if(*p < menor)
		{
			menor = *p;
		}
	}

}


int main()
{
	list<int> lista; // ponteiro lista 

	int maior = -5000;
	int menor = 5000;
	int x;

	cin >> x;
	while(x != 0)
	{
		lista.push_front(x);
		cin >> x;
		maiorMenor(lista, menor, maior);
	}



	cout << "menor: " << menor << endl;
	cout << "maior: " << maior << endl;



	return 0;
}
