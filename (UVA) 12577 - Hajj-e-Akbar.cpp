#include <iostream>
#include <string>
using namespace std;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int test = 1;
    string in;
    while(cin >> in) {
        if(in == "*") break;
        if(in == "Hajj") cout << "Case " << test << ": " << "Hajj-e-Akbar\n";
        if(in == "Umrah") cout << "Case " << test << ": " << "Hajj-e-Asghar\n";
        test++;
    }
    return 0;
}
