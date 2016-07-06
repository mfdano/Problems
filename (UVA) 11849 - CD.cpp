#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int64 n,m,cd,both;
  while(cin >> n >> m) {
    if(n == 0 && m == 0) break;
    set <int64> s;
    both = 0;
    while(n--) {
      cin >> cd;
      s.insert(cd);
    }
    while(m--) {
      cin >> cd;
      if(s.find(cd) != s.end()) {
        both++;
      }
    }
    cout << both << "\n";
  }
  return 0;
}
