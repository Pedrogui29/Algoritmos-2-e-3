#include<iostream>
#include<list>

using namespace std;

struct no
{
	int v;
	int peso;
};

void cria_aresta(list<no>adj[], int u, int v, int p, int orientado)
{
	no aux;

	aux.v = v;
	aux.peso = p;

	adj[u].push_back(aux);

	if(orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}
}

int main()
{
	list<no>adj[10];
	list<no>::iterator it;
	int nVertices;
	int o, d, a;
	int peso;
	int orientado;

	cin >> nVertices;
	cin >> orientado;
	cin >> o >> d >> a;

	while(o != -1 && d != -1 && a != -1)
	{
		cria_aresta(adj, o, d, a, orientado);
		cin >> o >> d >> a;
	}

	for(int i = 0; i < nVertices; i++)
	{
		for(it = adj[i].begin(); it != adj[i].end(); it++)
			cout << i << " " << it->v << " " << it->peso << endl;
	}
	return 0;
}
