#include<iostream>
#include<list>

using namespace std;

int main()
{
	list<int>lista;
	list<int>::iterator p;

	lista.push_front(2);
	lista.push_front(1);
	lista.push_front(3);

	for(p = lista.begin(); p != lista.end(); p++)
	{
		cout << *p << " ";
	}
	cout << endl;
}
