// Utilizaremos pilas y greedy para resolver el problema. Igual que el anterior pero para k = 12
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <stack>
#include <vector>

typedef unsigned long long ull;

using namespace std;

void maximo_potencial(const string &numero, stack<int> &pila)
{ // 7364324241225433445422232322233434224835321253334532333323166227675321322533332522422446233324232434
    int k = 12;
    int n = (int)numero.size(); // No se que retornen estes coses pero si no les convertixc (cast) sempre me dona problemes
    int eliminar_12 = (n - k);  // IIS me ha acostumat a gastar els parentesis, sino ara ho vec raro
    if (eliminar_12 < 0)        // Me pegava una rallaes si no feia aso.
    {
        eliminar_12 = 0;
    }

    for (char c : numero)
    {
        if (c < '0' || c > '9') // Per si acas, no sas lo que se pots troabar en els Inputs
            continue;
        int digito = (c - '0');
        while (!pila.empty() && (eliminar_12 > 0) && (pila.top() < digito))
        {
            pila.pop();
            (eliminar_12--);
        }
        pila.push(digito);
    }
    while (eliminar_12 > 0 && !pila.empty())
    {
        pila.pop();
        (eliminar_12--);
    }
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
        stack<int> pila;
        maximo_potencial(line, pila);

        ull numero = 0;
        ull mult = 1;
        for (int i = 0; i < 12 && !pila.empty(); i++)
        {
            int top = pila.top(); // Guardamos el tope porque si utilizo directamente pila.top() para calcular me da error y no se porque
            pila.pop();           // Ahora si lo quito
            // if (top == -1) break; // Per si acas
            numero += (top * mult); // Gatar el pow() me donava problemes aixina que ha fero per força bruta
            mult *= 10;             // Que locura
        }
        suma += numero;
    }
    file.close();
    cout << suma << endl;
    return 0;
}