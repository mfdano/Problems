#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int array[n];
    for(int i=0;i<n;i++) cin >> array[i];
    sort(array,array+n);
    for(int i=0;i<n;i++) cout << array[i] << "\n";
    return 0;
}
