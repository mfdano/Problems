#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
const int INF = (1<<30);
int amount[MAX+5];
int channels[MAX+5];
int bfs(int,int);
bool isValid(int,int);
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int o,d,k,banned;
  while(cin >> o >> d >> k) {
    if(o == 0 && d == 0 && k == 0) break;
    for(int i=0;i<=MAX;i++) {
      channels[i] = 1;
      amount[i] = INF;
    }
    while(k--) {
      cin >> banned;
      channels[banned] = 0;
    }
    cout << bfs(o,d) << "\n";
  }
  return 0;
}

int bfs(int o, int d) {
  queue< pair<int,int> > q;
  pair <int,int> s;
  s.first = o;
  s.second = 0;
  q.push(s);
  amount[s.first] = 0;
  while(!q.empty()) {
    pair <int,int> a = q.front();
    q.pop();
    if(a.first == d) return a.second;
    if(isValid(a.first + 1,a.second + 1)) q.push(make_pair(a.first + 1,a.second + 1));
    if(isValid(a.first - 1,a.second + 1)) q.push(make_pair(a.first - 1,a.second + 1));
    if(isValid(a.first * 3,a.second + 1)) q.push(make_pair(a.first * 3,a.second + 1));
    if(isValid(a.first * 2,a.second + 1)) q.push(make_pair(a.first * 2,a.second + 1));
    if(a.first%2 == 0) if(isValid(a.first/2,a.second + 1)) q.push(make_pair(a.first/2,a.second + 1));
  }
  return -1;
}

bool isValid(int idx,int c) {
  if(idx <= MAX && idx >= 1 && channels[idx] == 1 && c < amount[idx]) {
    pair <int,int> newc;
    newc.first = idx;
    newc.second = c;
    amount[newc.first] = newc.second;
    return true;
  }
  return false;
}
