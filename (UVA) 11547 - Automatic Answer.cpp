#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int test,n,sz;
    string num;
    ostringstream ostr;
    cin >> test;
    while(test--) {
        cin >> n;
        n = (n*315) + 36962;
        ostr << n;
        num = ostr.str();
        sz = num.size();
        cout << num[sz-2] << "\n";
    }
    return 0;
}
