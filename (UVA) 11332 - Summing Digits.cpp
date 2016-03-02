#include <iostream>
#include <string>
using namespace std;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string number;
    int sz,sum;
    while(cin >> number) {
        if(number == "0") break;
        sz = number.size();
        while(sz > 1) {
            sum = 0;
            for(int i=0;i<sz;i++) sum += (number[i] - '0');
            number = to_string(sum);
            sz = number.size();
        }
        cout << number << "\n";
    }
    return 0;
}
