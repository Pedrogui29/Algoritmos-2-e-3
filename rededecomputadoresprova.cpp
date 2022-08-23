#include<iomanip>
#include<iostream>
#include<stdio.h>
#include<locale.h>
#include<cmath>
#include<list>
#include<climits>

using namespace std;

struct no
{
	int v;
	float peso;
};

void MST_PRIM(list<no>adj[], int nVertices, int start)
{
	bool intree[100];
	int distance[100];
	int parent[100];
	int u;
	int v;
	float weight;
	list<no>::iterator p;
	int dist;
	int custo = 0;
	int destino;

	for(u = 0; u < nVertices; u++)
	{
		intree[u] = false;
		distance[u] = INT_MAX;
		parent[u] = -1;
	}

	distance[start] = 0;
	v = start;

	while(intree[v] == false)
	{
		intree[v] = true;

		for(p = adj[v].begin(); p != adj[v].end(); p++)
		{
			destino = p->v;
			weight = p->peso;

			if(distance[destino] > weight && intree[destino] == false)
			{
				distance[destino] = weight;
				parent[destino] = v;
			}
		}

		v = 0;
		dist = INT_MAX;

		for(u = 0; u < nVertices; u++)
		{
			if(intree[u] == false && dist > distance[u])
			{
				dist = distance[u];
				v = u;
			}
		}
	}

	cout << "Arvore Geradora Minima:" << endl;

	for(int i = 1; i < nVertices; i++)
	{
		p = adj[i].begin();
		cout << parent[i] << " ";

		for(u = 1; u < nVertices; u++)
		{
			if(p->peso == distance[i])
			{
				destino = i;
				break;
			}
			p++;
		}
		custo = custo + distance[i];
		cout << destino << endl;
	}
	cout << "Custo: " << custo << endl;
	cout << endl;
}

void cria_ar(list<no>adj[], int u, int v, int p, int orientado)
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
	int nv;
	int orientado;
	int x, y;
	int p;
	list<no>::iterator it;
	int ini;

	cin >> nv;
	cin >> orientado;
	cin >> ini;
	cin >> x;
	cin >> y;
	cin >> p;

	while(x != -1 && y != -1 && p != -1)
	{
		cria_ar(adj, x, y, p, orientado);
		cin >> x;
		cin >> y;
		cin >> p;
	}

	MST_PRIM(adj, nv, ini);

	return 0;
}
