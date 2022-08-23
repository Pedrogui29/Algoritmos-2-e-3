#include<iostream>

using namespace std;

int main ()
{

	char *gabarito = NULL;
	char *g;
	char *respostas = NULL;
	char *r;
	int questoescertas = 0;


	//alocando o gabarito
	gabarito = new char [9];
	//preencher vetor
	for(g = gabarito; g < gabarito + 10; g++)
		cin >> *g;

	//alocando as respostas
	respostas = new char [9];
	//preencher vetor
	for(r = respostas; r < respostas + 10; r++)
		cin >> *r;



	//comparando as respostas
	r = respostas;
	for (g = gabarito; g < gabarito + 10; g++)   // varrer v
	{
		if (*g  ==  *r)  // se o gabarito for igual resposta;
		{
			questoescertas++; // incrementar contador
			r++;
		}
		r++;
	}

	cout << questoescertas << endl;

	return 0;
}
