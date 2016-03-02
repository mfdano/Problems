#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int circular_list[100];
    int a,b,c;
    while(cin >> a >> b) {
        if(a == -1 && b == -1) break;
        if(a == b) cout << "0\n";
        else {
            if(b < a) swap(a,b);
            cout << min(b-a,a+(99-b)+1) << "\n";
        }
    }
    return 0;
}
