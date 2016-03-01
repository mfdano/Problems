#include <iostream>
using namespace std;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int l,w,h,test;
    cin >> test;
    for(int i=1;i<=test;i++) {
        cin >> l >> w >> h;
        if(l <= 20 && w <= 20 && h <= 20) cout << "Case " << i << ": " << "good\n";
        else cout << "Case " << i << ": " << "bad\n";
    }
    return 0;
}
