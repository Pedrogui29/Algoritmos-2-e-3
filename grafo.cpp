#include <iostream>
#include <list>
using namespace std;

struct no
{
	int v; // Vertice de destino
	int peso; // Peso da aresta
};

int main()
{
	list<no> adj[10]; // lista de adjacencias
	int nVertices; // No de vercices do grafo
	int u, v; // vertices de origem e destino
	int p; // peso da aresta
	no aux; // var aux de insercao
	int i; // contador
	int orientado; // orientado
	list<no>::iterator q; // iterador p/ varrer lista adjc.
// Ler No de vertices
	cin >> nVertices;

	// orientado = 1 / nao orientado = 0
	cin >> orientado;

// Ler aresta e inserir no grafo
	for(i = 0; i < 3; i++)
	{
		if(orientado == 0)
		{
			cin >> u >> v >> p;
			aux.v = v;
			aux.peso = p;
			adj[u].push_back(aux);
		}
		else if(orientado == 1)
		{
			aux.v = u;
			adj[v].push_back(aux);
		}
	}
// Mostrar lista de adjc. p/ cada nó
	for(i = 0; i < 3; i++)
		for(q = adj[i].begin(); q != adj[i].end(); q++)
			cout << i << " " << q->v << " " << q->peso << endl;

	return 0;                                                                   
}
