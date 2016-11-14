#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int test,ng,nm,m;
  cin >> test;
  while(test--) {
    cin >> ng >> nm;
    vector<int> ng_monsters;
    vector<int> nm_monsters;
    for(int i=0;i<ng;i++) {
      cin >> m;
      ng_monsters.push_back(m);
    }
    for(int i=0;i<nm;i++) {
      cin >> m;
      nm_monsters.push_back(m);
    }
    sort(ng_monsters.begin(),ng_monsters.end());
    sort(nm_monsters.begin(),nm_monsters.end());
    while(!ng_monsters.empty() && !nm_monsters.empty()) {
      if(ng_monsters[0] >= nm_monsters[0]) nm_monsters.erase(nm_monsters.begin());
      else ng_monsters.erase(ng_monsters.begin());
    }
    if(!ng_monsters.empty()) cout << "Godzilla\n";
    else if(!nm_monsters.empty()) cout << "MechaGodzilla\n";
  }
  return 0;
}
