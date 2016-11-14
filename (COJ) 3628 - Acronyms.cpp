#include <bits/stdc++.h>
using namespace std;
bool check(string,string);
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  string line1,line2;
  while(getline(cin,line1) && getline(cin,line2)) {
    cout << (check(line1,line2) ? "yes" : "no") << "\n";
  }
  return 0;
}
bool check(string s1, string s2) {
  int sz1 = s1.size();
  int sz2 = s2.size();
  queue <int> q1;
  queue <int> q2;
  q1.push(0); q2.push(0);
  for(int i=0;i<sz1;i++) {
    if(s1[i] == ' ') q1.push(i+1);
  }
  for(int i=0;i<sz2;i++) {
    if(s2[i] == ' ') q2.push(i+1);
  }
  if(q1.size() != q2.size()) return false;
  else {
    while(!q1.empty()) {
      if(s1[q1.front()] != s2[q2.front()]) return false;
      q1.pop(); q2.pop();
    }
  }
  return true;
}
