#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n,m,idx,a,b;
  while(cin >> n >> m) {
  	map <int, vector< pair <int,int> > > adjlist;
  	for(int i=1;i<=n;i++) {
  		cin >> idx;
  		adjlist[idx].push_back(make_pair(idx,i));
  	}
  	while(m--) {
  		cin >> b >> a;
  		if(b > adjlist[a].size()) cout << "0\n";
  		else cout << ((adjlist[a][b-1]).second) << "\n";
  	}
  }
  return 0;
}
