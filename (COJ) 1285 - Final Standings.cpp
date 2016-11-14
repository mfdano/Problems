#include <bits/stdc++.h>
using namespace std;
struct teams {
	int idx;
	int problems;
	int i;
};
bool operator < (teams a, teams b) { return (a.problems < b.problems) || (a.problems == b.problems && a.i > b.i); }
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	teams t[n];
	for(int i=0;i<n;i++) {
		cin >> t[i].idx >> t[i].problems;
		t[i].i = i;
	}
	sort(t,t+n);
	for(int i=n-1;i>=0;i--) {
		cout << t[i].idx << " " << t[i].problems << "\n";
	}
	return 0;
}
