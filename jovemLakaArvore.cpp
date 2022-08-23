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

void preOrd(treenodeptr arvore, int pre[], int &i)
{
  if (arvore != NULL)
  {
    pre[i++] = arvore->info;
    preOrd(arvore->esq, pre, i);
    preOrd(arvore->dir, pre, i);
  }
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

void posOrd(treenodeptr arvore, int pos[], int &i)
{
  if (arvore != NULL)
  {
    posOrd(arvore->esq, pos, i);
    posOrd(arvore->dir, pos, i);
    pos[i++] = arvore->info;
  }
}

void menorcaminho(treenodeptr arvore, int n, int x)
{
  int pre[100], pos[100], em[100];    // vetor de preOrdem, emOrdem e posOrdem
  int i = 1;                          // indice dos vetores
  int menor_pre, menor_pos, menor_em; // menor elemento de cada caminho

  preOrd(arvore, pre, i);
  i = 1;
  posOrd(arvore, pos, i);
  i = 1;
  emOrd(arvore, em, i);

  for (i = 1; i < n; i++)
  {
    if (pre[i] == x)
      menor_pre = i;
  }
  for (i = 1; i < n; i++)
  {
    if (pos[i] == x)
      menor_pos = i;
  }
  for (i = 1; i < n; i++)
  {
    if (em[i] == x)
      menor_em = i;
  }

  if (menor_pre < menor_pos && menor_pre < menor_em)
    cout << "Pre" << endl;
  else if (menor_pos < menor_pre && menor_pos < menor_em)
    cout << "Pos" << endl;
  else if (menor_em < menor_pre && menor_em < menor_pos)
    cout << "Em" << endl;
}

int main()
{
  treenodeptr arvore = NULL; // ponteiro para a raiz da arvore
  int aux;                   // auxiliar para inserir os elementos
  int n = 1;                 // número de elementos da árvore
  int x;                     // elemento que representa a cidade que o chocolate está localizado

  cin >> aux;
  while (aux != -1)
  {
    tInsere(arvore, aux);
    cin >> aux;
    n++;
  }
  cin >> x;

  menorcaminho(arvore, n, x);

  return 0;
}