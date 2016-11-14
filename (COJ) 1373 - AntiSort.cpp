#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int test,n,a,d;
  cin >> test;
  cout << test << "\n\n";
  while(test--) {
    cin >> n;
    int antisort[n];
    for(int i=0;i<n;i++) cin >> antisort[i];
    sort(antisort,antisort+n);
    for(int i=n-1;i>=1;i--) if(antisort[i] > antisort[i-1]) { a=i; break; }
    swap(antisort[a-1],antisort[a]);
    cout << n << "\n";
    for(int i=0;i<n;i++) cout << antisort[i] << " ";
    cout << "\n";
    swap(antisort[a-1],antisort[a]);
    for(int i=0;i<n-1;i++) if(antisort[i] < antisort[i+1]) { swap(antisort[i],antisort[i+1]); break; }
    for(int i=n-1;i>=0;i--) cout << antisort[i] << " ";
    cout << "\n";
    if(test) cout << "\n";
  }
  return 0;
}
