#include <iostream>
using namespace std;
int gcd(int,int);
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int a,b,c;
    while(cin >> a >> b  >> c) {
        if(a == 0 && b == 0 && c== 0) break;
        if((c%gcd(a,b)) == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
int gcd(int a,int b) {
    if(b == 0) return a;
    return gcd(b,a%b);
}
