#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;
void nBeam(vector <string> &matriu, int col){

}
int main(int argc, char const *argv[])
{
    ifstream fich("input.txt");
    string l1;
    vector <string> matriu;

    while (getline(fich, l1))
    {
        matriu.push_back(l1);
    }
    int pos_S = matriu[0].find('S');

    long count = 0;


    cout << count << endl;
    fich.close();

    return 0;
}