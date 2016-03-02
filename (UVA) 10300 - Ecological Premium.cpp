#include <iostream>
using namespace std;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int test,n,a,b,c,s;
    cin >> test;
    while(test--) {
        cin >> n;
        s = 0;
        while(n--) {
            cin >> a >> b >> c;
            s += a*c;
        }
        cout << s << "\n";
    }
    return 0;
}
