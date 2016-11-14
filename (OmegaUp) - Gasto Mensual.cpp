#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
int days[MAX];
int solve(int,int,int,int);
bool check(int,int,int);
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N,M,sum,lower,upper;
  cin >> N >> M;
  upper = 0, lower = -1;
  for(int i=0;i<N;i++) {
    cin >> days[i];
    upper += days[i];
    lower = max(days[i],lower);
  }
  if(M == 1) cout << upper << "\n";
  else if(M == N) cout << lower << "\n";
  else cout << solve(lower,upper,N,M) << "\n";
  return 0;
}

int solve(int lower, int upper, int N, int M) {
  int middle,ans;
  while(lower <= upper) {
    middle = (lower + upper)/2;
    if(check(N,M,middle)) {
      ans = middle;
      upper = middle - 1;
    } else lower = middle + 1;
  }
  return ans;
}

bool check(int n, int m, int total) {
  int months = 0, current;
  current = days[0];
  for(int i=0;i<n-1;i++) {
    if(current + days[i+1] <= total) {
      current += days[i+1];
      continue;
    } else {
      months++;
      current = days[i+1];
    }
  }
  if(current <= total) months++;
  return (months <= m) ? true : false;
}
