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
void Ordenacao(treenodeptr arvore, int elementos[], int &i)
{
	if (arvore != NULL)
	{
		Ordenacao(arvore->esq, elementos, i);
		elementos[i] = arvore->info;
		i++;
		Ordenacao(arvore->dir, elementos, i);
	}
}
void MaiorMenor(treenodeptr arvore, int n, int &maior, int &menor)
{
	int elementos[100]; 
	int i = 1;          

	Ordenacao(arvore, elementos, i);

	for (i = 1; i < n; i++)
	{
		if (i == 1)
		{
			maior = elementos[i];
			menor = elementos[i];
		}
		else
		{
			if (elementos[i] > maior)
				maior = elementos[i];
			if (elementos[i] < menor)
				menor = elementos[i];
		}
	}
}


int main()
{

	treenodeptr arvore = NULL;

	int numeros;
	int n = 1 ;
	int maior, menor;


	cin >> numeros;
	while (numeros != -1)
	{
		tInsere(arvore, numeros);
		cin >> numeros;
		n++;
	}
	
	MaiorMenor(arvore, n, maior, menor);

	cout << menor << " e " << maior << endl;
	
	return 0;
}

