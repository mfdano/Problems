#include <iostream>
using namespace std;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int test=1,a,b,n,e;
    while(cin >> n) {
        if(n == 0) break;
        a = b = 0;
        while(n--) {
            cin >> e;
            if(e == 0) b++;
            else a++;
        }
        cout << "Case " << test << ": " << a-b << "\n";
        test++;
    }
    return 0;
}
