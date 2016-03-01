#include <iostream>
#include <string>
using namespace std;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int test,sz;
    string str;
    cin >> test;
    while(test--) {
        cin >> str;
        sz = str.size();
        if(str == "1" || str == "4" || str == "78") cout << "+\n";
        else if(str[sz-1] == '5' && str[sz-2] == '3') cout << "-\n";
        else if(str[0] == '9' && str[sz-1] == '4') cout << "*\n";
        else cout << "?\n";
    }
    return 0;
}
