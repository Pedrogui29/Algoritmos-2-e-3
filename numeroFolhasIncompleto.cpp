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

void contapreOrdem (treenodeptr arvore, int &f)
{
f=0;
if (arvore != NULL)
{
    contapreOrdem(arvore->esq,f);
    contapreOrdem(arvore->dir,f);
    if(arvore->esq==NULL && arvore->dir==NULL)
    f++;
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
     int quant;
     int folha;
	 
	 treenodeptr arvore=NULL;
	 
	 cin>>quant;
	 cin>>num;
	 while(num!=-1){
	     tInsere(arvore,num);
	     cin>>num;
	 }
	 
	 contapreOrdem  (arvore, folha);
	 
	 
	 cout << folha << endl;
	 
	 

	 
	 return 0;
 }