#include <iostream>
#include <math.h>
using namespace std;

// Função que implementa a busca sequencial
// Se x for encontrado, retorna a posição do mesmo no vetor
// Se x não for encontrado, retorna -1


int sequencial(int vet[], int tam, int x)
{
	bool achou = false; // var aux p/ busca
	int i = 0; // contador
	int res;
	while (achou == false && i < tam)
		achou = vet[i++] == x;
	if (achou)
	{
		res = (i - 1);
		return res;
	}
	else
	{
		res = -1;
		return res;
	}
}

int main()
{

	int vetor[100]; // Vetor que será armazenado os elementos
	int n; // tamanho do vetor 
	int i; // contador 
	int p; // elemento que armazena no vetor
	int x; // numero buscado
	int res; //resultado da função

	cin >> p;
	i = 0 ;
	while(p != -1)
	{
		vetor[i] = p;
		i ++;
		cin >> p;
	}
	n = i;
	
	cin >> x;

    res = sequencial(vetor, n, x);
    
    if(res == -1){
		cout << x << " nao foi encontrado" << endl;
	}
	else{
		cout << x << " foi encontrado na posicao " << res << endl; 
	}
    
    
    

	return 0;
}
