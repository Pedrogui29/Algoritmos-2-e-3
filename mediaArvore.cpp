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
else
if (x < p->info) // insere na subarvore esquerda
tInsere(p->esq,x);
else // insere na subarvore direita
tInsere(p->dir,x);
}

void contapreOrdem (treenodeptr arvore, int &n)
{

if (arvore != NULL)
{
n++;
contapreOrdem(arvore->esq, n);
contapreOrdem(arvore->dir, n);
}
}


int contaNos(treenodeptr arvore)
{
	int n=0;//conta quantidade de nós 
	contapreOrdem(arvore,n);
	return n;
	
}

 int main(){
	 
	 int num;
	 double quant=0;
	 double soma=0;
	 double media;
	 
	 treenodeptr arvore=NULL;
	 
	 cin>>num;
	 while(num!=-1){
	 tInsere(arvore,num);
	 soma= soma+num;
	 quant++;
	 cin>>num;
     }
	  media=soma/quant;
	  cout << fixed << setprecision(2);
	  cout << "Media: " << media << endl;
	 
	 return 0;
 }