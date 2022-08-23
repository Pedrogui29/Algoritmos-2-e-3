#include<iostream>
#include<list>
#include<climits>

using namespace std;

struct no
{
	int peso;
	int v;
	int temp;
};

void dijkstra(list<no>adj[], int nVertices, int start, int end)
{
	bool intree[100];
	int parent[100];
	int weight;
	int u, v;
	int z;
	list<no>::iterator x;
	list<no>::iterator it;
	list<int> pilha;
	int c;
	int dist;
	int destino;
	int distance[100];

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

		for(x = adj[v].begin(); x != adj[v].end(); x++)
		{
			destino = x->v;
			weight = x->peso;

			if(distance[destino] > distance[v] + weight)
			{
				distance[destino] = distance[v] + weight;
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

	c = end;
	pilha.push_back(c);

	while(c != start)
	{
		c = parent[c];
		pilha.push_front(c);
	}

	cout << "Menor caminho:";

	while(!pilha.empty())
	{
		z = *pilha.begin();
		pilha.pop_front();
		cout << " " << z << endl;
	}

	cout << "Custo: " << distance[end] << endl;
}

void aresta(list<no>adj[], int u, int v, int p, int orientado)
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
	int nVertices;
	int u;
	int v;
	int p;
	int start;
	int end;
	int orientado;

	cin >> nVertices;

	list<no>adj[nVertices];
	list<no>::iterator it;

	cin >> orientado;
	cin >> start;
	cin >> end;
	cin >> u >> v >> p;

	while(u != -1 && v != -1 && p != -1)
	{
		aresta(adj, u, v, p, orientado);
		cin >> u >> v >> p;
	}

	dijkstra(adj, nVertices, start, end);
	return 0;
}
