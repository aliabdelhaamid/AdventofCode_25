// Aso es una animalada, aso no pot ser mes a lo bruto

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(void)
{
    ll minimo, maximo;
    char guion;
    string linea;
    vector<pair<ll, ll>> rangos;
    ll frescos = 0;
    ifstream archivo("input.txt");
    if (!archivo.is_open())
    {
        cerr << "Error al abrir el archivo." << endl;
        return (1);
    }

    while (getline(archivo, linea))
    {
        if (linea.empty() || linea[0] == '\n')
        {
            break;
        }
        istringstream ss(linea);
        ss >> minimo >> guion >> maximo;
        rangos.push_back({minimo, maximo});
    }
    archivo.close();
    sort(rangos.begin(), rangos.end());

    vector<pair<ll, ll>> rangos_unidos;
    if (!rangos.empty())
    {
        ll inicio = rangos[0].first;
        ll fin = rangos[0].second;
        for (int i = 1; i < rangos.size(); ++i)
        {
            const auto &r = rangos[i];
            if (r.first <= fin + 1)
            {
                fin = max(fin, r.second);
            }
            else
            {
                rangos_unidos.push_back({inicio, fin});
                inicio = r.first;
                fin = r.second;
            }
        }
        rangos_unidos.push_back({inicio, fin});
    }
    for (const auto &r : rangos_unidos)
    {
        frescos += (r.second - r.first + 1);
    }
    cout << frescos << endl;
    return 0;
}