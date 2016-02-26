#include <iostream>
#include <string>
using namespace std;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string word;
    int ntest = 0;
    while(cin >> word) {
        if(word == "#") break;
        ntest++;
        if(word == "HELLO") word = "ENGLISH";
        else if(word == "HOLA") word = "SPANISH";
        else if(word == "HALLO") word = "GERMAN";
        else if(word == "BONJOUR") word = "FRENCH";
        else if(word == "CIAO") word = "ITALIAN";
        else if(word == "ZDRAVSTVUJTE") word = "RUSSIAN";
        else word = "UNKNOWN";
        cout << "Case " << ntest << ": " << word << "\n";
    }
    return 0;
}
