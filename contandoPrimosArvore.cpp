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

void emOrd(treenodeptr arvore, int em[], int &i)
{
  if (arvore != NULL)
  {
    emOrd(arvore->esq, em, i);
    em[i++] = arvore->info;
    emOrd(arvore->dir, em, i);
  }
}

int contaPrimos(treenodeptr arvore)
{
  int i = 1, j; // indice dos vetores
  int n;        // numero de elementos do vetor
  int cont; // contador de primos 
  int primos = 0; // numero de primos
  int em[100]; // vetor da funcao emOrd

  emOrd(arvore, em, i);
  n = i - 1;

  for (i = 1; i <= n; i++)
  {
    cont = 0;
    for (j = 1; j <= em[i]; j++)
    {
      if (em[i] % j == 0)
        cont++;
    }
    if (cont == 2)
      primos++;
  }
  return primos;
}

int main()
{
  treenodeptr arvore = NULL; // ponteiro para a raiz da arvore
  int numeros;               // numeros que serao inseridos 
  int primos;                 

  cin >> numeros;
  while (numeros != -1)
  {
    tInsere(arvore, numeros);
    cin >> numeros;
  }

  primos = contaPrimos(arvore);

  cout << primos << " numeros primos" << endl;

  return 0;
}