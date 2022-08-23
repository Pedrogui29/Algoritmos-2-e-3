#include <iostream>
#include <list>
#include <climits>
#include<iomanip>
using namespace std;
struct no
{
	int v; //vertice adjacente
	float peso; //peso da aresta
};
// Cria a aresta (u,v) com peso peso.
// Se orientado=0, cria um grafo não orientado, se orientado=1, cria um grafo orientado
void cria_aresta (list<no> adj[], int u, int v, float peso, int orientado)
{
	no aux; //variavel auxiliar para inserir a aresta na lista de adjacencias
	aux.peso = peso;
	aux.v = v;
	adj[u].push_back(aux);
	if (orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}
}
// Implementa o algoritmo de Prim para arvore geradora minima
void prim (list<no>adj[], int nVertices, int start)
{
	bool intree[100]; //mostra se o vertice ja foi adicionado na arvore
	float distance[100]; // distancia entre os vertices
	int parent[100]; // vertice de origem
	int i; //contador
	int destino; //vertice de destino
	float weight; //peso da aresta
	int v; // vertice que esta sendo analizado
	float dist; // var aux para determinar proximo vertice a ser explorado
	int aux; //variavel auxiliar
	float custo; // custo da arvore geradora minima
	list<no>::iterator p; // var aux para varrer a lista de adjacências
	for (i = 0; i < nVertices; i++)
	{
		intree[i] = false;
		distance[i] = INT_MAX;
		parent[i] = -1;
	}
	distance[start] = 0;
	v = start;
	while (intree[v] == false)
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
		for(i = 0; i < nVertices; i++)
		{
			if((intree[i] == false) && (dist > distance[i]))
			{
				dist = distance[i];
				v = i;
			}
		}
	}
	//Arvore geradora minima
	custo = 0;
	cout << "Ligacoes: " << endl;
	for(i = 0; i < nVertices; i++)
	{
		if(parent[i] != -1)
			cout << parent[i] << " " << i << endl;
		custo += distance[i]; // Custo total;       }
		// Custo total
		cout << fixed << setprecision(1);
		cout << "Custo total: " << custo << " m" << endl;
		return;
	}
}
int main()
{
	list<no> adj[100]; // lista de adjacencias
	int nVertices; // numero de vertices do grafo
	int start; //vertice inicial

	int u, v; // vertices de origem e destino de uma aresta
	float peso; //peso da aresta
	int orientado = 0; //1:orientado  0:nao orientado
	// Lendo quantidade de vertices e vertice inicial
	cin >> nVertices >> start;
	cin >> u >> v >> peso;
	// Lendo arestas
	while ((u != -1) && (v != -1) && (peso != -1))
	{
		cria_aresta(adj, u, v, peso, orientado);
		cin >> u >> v >> peso;
	}
	// Arvore geradora minima
	prim(adj, nVertices, start);
	return 0;
}
