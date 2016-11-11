#include <bits/stdc++.h>
using namespace std;
int binary_search(vector<int>&,int);
int main() {
	cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n,d,r,bus;
  while(cin >> n >> d >> r) {
  	if(!(n && d && r)) break;
  	vector <int> morning(n);
  	vector <int> evening(n);
  	for(int i=0;i<n;i++) cin >> morning[i];
  	for(int i=0;i<n;i++) cin >> evening[i];
  	sort(morning.begin(),morning.end());
  	sort(evening.begin(),evening.end());
  	int total = 0;
  	for(int i=0,j=n-1;i<n;i++,j--) {
  		bus = morning[i] + evening[j];
  		if(bus > d) total += ((bus-d)*r);
  	}
  	cout << total << "\n";
  }
  return 0;
}
