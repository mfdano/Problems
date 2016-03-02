#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n,b,h,w,p,a,t,ans;
    while(cin >> n >> b >> h >> w) {
        ans = 10000000;
        while(h--) {
            cin >> p;
            for(int i=1;i<=w;i++) {
                cin >> a;
                if(a >= n) {
                    t = p*n;
                    ans = min(t,ans);
                }
            }
        }
        if(ans <= b) cout << ans << "\n";
        else cout << "stay home\n";
    }
    return 0;
}
