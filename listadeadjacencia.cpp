#include <iostream>
#include <list>
using namespace std;
struct no
{
	int v; // vertice de destino da aresta
	int peso; // peso da aresta
};
int main()
{
	list<no> adj[10]; // lista de adjac�ncias
	int nVertices; // numero de v�rtices do grafo
	int u, v; // v�rtices de // origem e destino de uma aresta
	int p; // peso da aresta
	no aux; // var aux para inserir as arestas na lista de adjac�ncias
	int i; // contador
	list<no>::iterator q; // iterador para varrer a lista de adjac�ncias

	// Lendo numero de vertices do grafo
	cin >> nVertices;

	// Lendo aresta e inserindo no grafo
	// 0 1 3
	// 0 3 2
	// 1 2 5
	for(i = 0; i < 3; i++)
	{
		cin >> u >> v >> p;
		aux.v = v;
		aux.peso = p;
		adj[u].push_back(aux);
	}
	// Mostrando a lista de adjac�ncias
	cout << "Lista de adjacencia:" << endl;
	for(i = 0; i < nVertices; i++)
		for(q = adj[i].begin(); q != adj[i].end(); q++)
			cout << i << " " << q->v << " " << q->peso << endl;

	return 0;
}
