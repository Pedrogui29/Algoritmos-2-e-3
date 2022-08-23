#include <iostream>
using namespace std;

struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
};
typedef treenode *treenodeptr;

void tInsere(treenodeptr &p, int x)
{
	if (p == NULL) // insere na raiz
	{
		p = new treenode;
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;
	}
	else if (x < p->info) // insere na subarvore esquerda
		tInsere(p->esq, x);
	else // insere na subarvore direita
		tInsere(p->dir, x);
}

void OrdemDec(treenodeptr arvore) 
{
	if (arvore != NULL)
	{
		OrdemDec(arvore->dir);
		cout << arvore->info << " ";
		OrdemDec(arvore->esq);
	}
}

int main()
{
	treenodeptr arvore = NULL; 
	int numeros;                   

	cin >> numeros;
	while (numeros != -1)
	{
		tInsere(arvore, numeros);
		cin >> numeros;
	}

	OrdemDec(arvore);

	return 0;
}
