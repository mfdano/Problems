#include <bits/stdc++.h>
using namespace std;
const int INF = (1<<30);
const int MAX = 100000;
vector<int> triangularNumbers;
int memo[1000];
int dp(int,int);
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n,tn;
  triangularNumbers.push_back(0);
  for(int i=1;i<=100000;i++) {
    tn = (i*(i+1))/2;
    if(tn > 100000) break;
    triangularNumbers.push_back(tn);
  }
  int memo[MAX+1];
  for(int i=0;i<=MAX;i++) memo[i] = INF;
  memo[0] = 0;
  for(int i=1;i<=MAX;i++) {
    for(int j=0;j<triangularNumbers.size();j++) {
      if(triangularNumbers[j] <= i) memo[i] = min(memo[i - triangularNumbers[j]] + 1, memo[i]);
    }
  }
  while(cin >> n) {
  	cout << memo[n] << "\n";
  }
  return 0;
}
