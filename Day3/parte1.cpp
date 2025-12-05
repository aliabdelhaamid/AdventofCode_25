#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

typedef unsigned long long ull;

using namespace std;

int maximo_potencial(const string &numero, int k)
{ // 7364324241225433445422232322233434224835321253334532333323166227675321322533332522422446233324232434
    int comb_pot = 0;
    int max_der = -200000; // Numero muy pequeño (no me deja poner -inf)
    int aux;
    for (int i = numero.size() - 1; i >= 0; i--)
    {
        k = (numero[i] - '0');
        aux = (k * 10) + max_der;
        comb_pot = max(comb_pot, aux);
        max_der = max(max_der, k);
    }
    return (comb_pot);
}

int main(void)
{
    ull suma = 0;
    string line;
    ifstream file("input.txt");

    if (!(file.is_open()))
        throw runtime_error("No se pudo abrir el archivo");
    while (getline(file, line))
    {
        suma += maximo_potencial(line, 0);
    }
    file.close();
    cout << suma << endl;
    return 0;
}