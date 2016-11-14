#include <bits/stdc++.h>
using namespace std;
const int _max = 10005; 
struct flights {
	int start;
	int end;
	int price;
};
bool operator <(flights first, flights second) { return first.end < second.end; }
int next_upper_bound(int[],int,int);
int main() {
	cin.tie(0);
  ios_base::sync_with_stdio(0);
	int test, n, duration;
	cin >> test;
	while(test--) {
		cin >> n;
		flights _flights[n];
		for(int i=0;i<n;i++) {
			cin >> _flights[i].start >> duration >> _flights[i].price;
			_flights[i].end = _flights[i].start + duration;
		}
		sort(_flights,_flights+n);
		int pj[n];
		int ends[n];
		int dp[n+1];
		for(int i=0;i<n;i++) ends[i] = _flights[i].end;
		for(int i=n-1;i>=0;i--) pj[i] = next_upper_bound(ends,_flights[i].start,n);
		dp[0] = 0;
		for(int i=1;i<=n;i++) dp[i] = max(_flights[i-1].price + dp[pj[i-1]],dp[i-1]);
		cout << dp[n] << "\n";
	}
}
int next_upper_bound(int ends[], int k,int n) {
	int lower = 0;
  int upper = n; 
  while (lower < upper) {
    int middle = (lower + upper) / 2;
    if (k >= ends[middle]) lower = middle + 1;
    else upper = middle;
  }
  return lower;
}

/*
int next_lower_bound(int ends[], int k,int n) {
  int lower = 0;
  int upper = n; 
  while (lower < upper) {
    int middle = (lower + upper) / 2;
    if (k <= ends[middle]) upper = middle;
    else lower = middle + 1;
  }
  return lower;
}
*/
