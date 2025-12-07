#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream fich("input.txt");
    string l1;
    int count = 0;
    vector <vector<char> > matriu;

    while (getline(fich, l1))
    {
        vector <char > aux;
        for (int j = 0; j < l1.size(); j++)
        {
            aux.push_back(l1[j]);
        }
        matriu.push_back(aux);
    }

    cout << count << endl;
    fich.close();

    return 0;
}
