#include<iostream>
#include<list>
#include<climits>

using namespace std;

struct no
{
	int v;
	int peso;
};

void cria_aresta(list<no>adj[], int u, int v, int orientado)
{
	no aux;
	aux.v = v;
	adj[u].push_back(aux);

	if(orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}
}

void ordenacao_topologica(int f[], int nVertices)
{
	int u, i, uai;
	int vet[100];

	for(i = 0; i < nVertices; i++)
	{
		vet[i] = i;
	}

	for(u = 0; u < nVertices; u++)
	{
		for(i = u + 1; i < nVertices; i++)
		{
			if(f[vet[u]] < f[vet[i]])
			{
				uai = vet[u];
				vet[u] = vet[i];
				vet[i] = uai;
			}
		}
	}

	for(u = 0; u < nVertices; u++)
	{
		cout << vet[u] << " ";
	}
	cout << endl;
}

void dfs_visit(list<no> adj[], int nVertices, char color[], int pi[], int f[], int d[], int &time, int u)
{
	list<no>::iterator v;

	color[u] = 'g';
	d[u] = ++time;

	for(v = adj[u].begin(); v != adj[u].end(); v++)
	{
		if(color[v->v] == 'w')
		{
			pi[v->v] = u;
			dfs_visit(adj, nVertices, color, pi, f, d, time, v->v);
		}
	}

	color[u] = 'b';
	f[u] = ++time;
}

void dfs(list<no> adj[], int nVertices)
{
	char color[100];
	int pi[100];
	int f[100];
	int d[100];
	int time;
	int i;

	for(i = 0; i < nVertices; i++)
	{
		color[i] = 'w';
		pi[i] = -1;
	}

	time = 0;

	for(i = 0; i < nVertices; i++)
	{
		if(color[i] == 'w')
		{
			dfs_visit(adj, nVertices, color, pi, f, d, time, i);
		}
	}
	ordenacao_topologica(f, nVertices);
}

int main()
{
	list<no> adj[10];
	list<no>::iterator it;
	int nVertices;
	int orientado;
	int u, v;

	cin >> nVertices;
	cin >> orientado;
	cin >> u >> v;

	while(u != -1 && v != -1)
	{
		cria_aresta(adj, u, v, orientado);
		cin >> u >> v;
	}
	dfs(adj, nVertices);
	return 0;
}
