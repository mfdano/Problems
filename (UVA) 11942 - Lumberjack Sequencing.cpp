#include <iostream>
using namespace std;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int asc,des;
    int test,n1,n2;
    cin >> test;
    for(int t=0;t<test;t++) {
        asc = des = 0;
        for(int i=0;i<10;i++) {
            if(i == 0) {
                cin >> n2;
                continue;
            }
            n1 = n2;
            cin >> n2;
            if(n1 > n2) des++;
            if(n1 < n2) asc++;
        }
        if(t == 0) cout << "Lumberjacks:\n";
        if(asc == 9 || des == 9) cout << "Ordered\n";
        else cout << "Unordered\n";
    }
    return 0;
}
