#include <iostream>
#include <string>
using namespace std;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t,m;
    long long a;
    string o;
    cin >> t;
    a = 0;
    while(t--) {
        cin >> o;
        if(o == "donate") {
            cin >> m;
            a += m;
        } else cout << a << "\n";
    }
    return 0;
}
