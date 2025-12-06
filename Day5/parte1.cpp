#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

typedef long long ll;

int main(void)
{
    ll minimo, maximo;
    bool separador = false;
    char guion;
    string linea;
    vector<pair<ll, ll>> rangos;
    int frescos = 0;
    ifstream archivo("input.txt");
    if (!archivo.is_open())
    {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    while (getline(archivo, linea))
    {
        if (separador)
        { // Seran frescos si se encuentran en algun rango, si estan fuera se consideraran estropeados
            ll numero = stoll(linea);
            for (const auto &rango : rangos)
            {
                if (numero >= rango.first && numero <= rango.second)
                {
                    ++frescos;
                    break; // Per a no comprobar mes rangos que si no peta tot
                }
            }
            continue;
        }
        if (linea.empty() || linea[0] == '\n')
        {
            separador = true;
            continue;
        }
        istringstream ss(linea);
        ss >> minimo >> guion >> maximo;
        rangos.push_back({minimo, maximo});
    }
    archivo.close();
    cout << frescos << endl;
    return 0;
}