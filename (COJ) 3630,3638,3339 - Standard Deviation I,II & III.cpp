#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ld n,S;
  cout << fixed;
  cout << setprecision(6);
  while (cin >> n) {
    if(n == 0.0) break;
    S = sqrt((((n*(2.0*n+1.0)*(2.0*n-1.0))/3.0)-(n*n*n))/(n-1.0));
    cout << S << "\n";
  }
  return 0;
}
