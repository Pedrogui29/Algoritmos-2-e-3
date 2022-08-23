#include <iostream>

using namespace std;

struct dado
{
    int k;      // chave
    int status; // 0 = vazio e 1 = ocupado
};

int hash_aux(int k, int m) //função de hash aux
{
    return k % m;
}

int hash1(int k, int i, int m) // função hash1
{
    return (hash_aux(k, m) + i) % m;
}

int hash_insert(dado t[], int m, int k) //função hash para inserir elementos 
{
    int i = 0; 
    int j;

    do
    {
        j = hash1(k, i, m);

        if (t[j].status != 1)
        {
            t[j].k = k;
            t[j].status = 1;
            return j;
        }
        else
            i = i + 1;
    } while (i != m);
    return -1;
}

int main()
{
    dado tabela[20]; // tabela hash
    int key;      //chave
    int N;      //tamanho da tabela
    int j, i;   //aux
    int res; //resultado

    //Inserir o tamanho da tabela
    cin >> N;

    // Inicialização da tabela
    for (int j = 0; j < N; j++)
    {
        tabela[j].k = -1;

        tabela[j].status = 0;
    }

    //leitura da chave
    
    while (key != 0)
    {
        cin >> key;
    }

    // chamando função para mostrar na tabela 
    res = hash_insert(tabela, N, key);

    for (i = 0; i < N; i++)
    {
        cout << res << " ";
    }

    cout << endl;

    return 0;
}
