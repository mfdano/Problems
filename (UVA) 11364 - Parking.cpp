#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int test,n,s,stores[20];
    cin >> test;
    while(test--) {
        cin >> n;
        for(int i=0;i<n;i++) cin >> stores[i];
        sort(stores,stores+n);
        s = 0;
        for(int i=0;i<n-1;i++) s += (stores[i+1] - stores[i]);
        cout << s*2 << "\n";
    }
    return 0;
}
