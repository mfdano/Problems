#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ll N,T;
  char direction;
  string ledTop,ledBottom,led;
  while(cin >> N >> T >> direction) {
    getline(cin,ledTop);
    getline(cin,ledTop);
    getline(cin,led);
    getline(cin,ledBottom);
    cout << ledTop << "\n";
    string newled = "";
    for(int i=1;i<led.size()-1;i++) if(i%2 != 0) newled += led[i];
    if(direction == 'R') rotate(newled.rbegin(),newled.rbegin() + (T%N),newled.rend());
    if(direction == 'L') rotate(newled.begin(),newled.begin() + (T%N),newled.end());
    cout << "|";
    for(int i=0;i<N;i++) cout << newled[i] << "|";
    cout << "\n";
    cout << ledBottom << "\n";
  }
  return 0;
}
