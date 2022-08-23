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
	 
	 int num[20];
     int quant;
	 int pesq;
	 int i;
	 bool achou=false;
	 
	 treenodeptr arvore=NULL;
	 
	 cin>>quant;
	 
	 for(i=0;i<quant;i++){
		 cin>>num[i];
		 tInsere(arvore,num[i]);
	 }
	 
	 cin>>pesq;
	 
	 for(i=0;i<quant;i++){
		 if(num[i]==pesq)
		 achou=true;
	 	 
	 }
 
     if(achou==true)
     	cout << "Encontrado" << endl;
     else 
     	cout << "Nao encontrado" << endl;
	 
	 
	 

	 
	 return 0;
 }