#include <iostream>
#include <string>
using namespace std;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int test,sz;
    string word;
    cin >> test;
    while(test--) {
        cin >> word;
        sz = word.size();
        if(sz == 5) cout << "3\n";
        else if(word[0] == 'o' && word[1] == 'n') cout << "1\n";
        else if(word[0] == 'o' && word[2] == 'e') cout << "1\n";
        else if(word[1] == 'n' && word[2] == 'e') cout << "1\n";
        else cout << "2\n";
    }
    return 0;
}
