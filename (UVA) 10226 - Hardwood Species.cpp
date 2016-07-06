#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n,total=0;
  double p;
  string name;
  cin >> n;
  int i = 0;
  getline(cin,name);
  getline(cin,name);
  while(n--) {
    map <string,int>  trees;
    total = 0;
    while(getline(cin,name) && name != "") {
      trees[name]++;
      total++;
    }
    for(auto it : trees) {
      p = ((it.second * (double)100) / (double)total);
      cout << it.first << " ";
      cout << fixed;
      cout << setprecision(4);
      cout << p << "\n";
    }
    if(n) cout << "\n";
  }
  return 0;
}
