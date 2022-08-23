#include <iostream>
#include <iomanip>
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

void contapreOrdem (treenodeptr arvore, int &f)
{
	if (arvore != NULL)
	{
		contapreOrdem(arvore->esq, f);
		contapreOrdem(arvore->dir, f);
		if(arvore->esq == NULL && arvore->dir == NULL)
		{
			f++; // contador de folhas caso for null 
		}
	}
}


int contafolhas(treenodeptr arvore) 
{
	int f = 0; // conta quantidade de nós
	contapreOrdem(arvore, f);
	return f;

}

int main()
{

	int numero;
	int folhas;

	treenodeptr arvore = NULL;

	cin >> numero;
	while(numero != -1)
	{
		tInsere(arvore, numero);
		cin >> numero;
	}

	folhas = contafolhas (arvore);


	cout << "Numero de folhas: " <<  folhas << endl;




	return 0;
}
