#include <iostream>
#include <iostream>
#include <list>
#include<climits>

using namespace std;

struct no
{
	int v; // identificacao do pc
	float peso; // cabo a ser usado 
};

//Criacao as arestas
void cria_aresta(list<no>adj[], int u, int v, float p, int orientado)
{
	no aux; // var que coloca na lista de adjacencia

	aux.v = v;
	aux.peso = p;
	adj[u].push_back(aux);
	if (orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}

}
//Funcao Prim
void prim(list<no>adj[], int nVertices, int start)
{
	int u, v; // vértices de origem e destino de uma aresta
	bool intree[101];
	int parent[101];
	int destino;
	float weight;
	int dist;
	float distance[101];
	list<no>::iterator q; // iterador que varre a lista de adjacências
	float soma = 0; //var soma de pesos

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
		for(q = adj[v].begin(); q != adj[v].end(); q++ )
		{
			destino = q->v;
			weight = q->peso;
			if (distance[destino] > weight && intree[destino] == false)
			{
				distance[destino] = weight;
				parent[destino] = v;
			}
		}
		v = 0;
		dist = INT_MAX;
		for(u = 0; u < nVertices; u++)
		{
			if (intree[u] == false && dist > distance[u])
			{
				dist = distance[u];
				v = u;
			}
		}

	}
	//Saida de dados 
	cout << "Ligacoes: " << endl;
	for(u = 1; u < nVertices; u++)
	{
		cout << parent[u] << " " << u << endl;
		soma = soma + distance[u];
	}
	cout << "Custo total: " << soma << "m" << endl;

}

int main()
{
	list<no> adjacencia[101]; // lista de adjacências
	int numeropc; // quantidade de PCs
	int u, v; // ids em sequencia dos PCs
	float cabo; // cabo a ser usado (peso)
	int pcinicial ;//estado

	// Leitura pcs
	cin >> numeropc;

	//Leitura inicio
	cin >> pcinicial;

	// Leitura de ids e cabos
	cin >> u >> v >> cabo;
	while (u != -1 && v != -1 && cabo != -1)
	{
		
		cria_aresta(adjacencia, u, v, cabo, 0); //chamada da funcao
		cin >> u >> v >> cabo;
	}
	prim(adjacencia, numeropc, pcinicial); //chamada da funcao

	return 0;
}
