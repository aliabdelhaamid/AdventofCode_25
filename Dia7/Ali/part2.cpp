#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream fich("input.txt");
    string l1;
    int count = 0;
    vector <string> matriu;

    while (getline(fich, l1))
    {
        matriu.push_back(l1);
    }
    int pos_begin = matriu[0].find('S');
    
    cout << count << endl;
    fich.close();

    return 0;
}