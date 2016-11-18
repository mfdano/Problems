#include <bits/stdc++.h>
using namespace std;
bitset <50005> visited;
vector <int> length(50005);
vector <int> graph(50005);
int dfs(int);
int main() {
	cin.tie(0);
  ios_base::sync_with_stdio(0);
  int test,n,u,v;
  cin >> test;
  for(int t=1;t<=test;t++) {
  	cin >> n;
  	for(int i=1;i<=n;i++) {
  		visited[i] = false;
  	  length[i] = -1;
  	}
  	for(int i=0;i<n;i++) {
  		cin >> u >> v;
  		graph[u] = v;
  	}
  	int result,ans,_max;
  	_max = -1;
  	for(int i=1;i<=n;i++) {
  		result = (length[i] == -1) ? dfs(i) : length[i];
  		if(result > _max) {
  			_max = result;
  			ans = i;
  		}
  	}
  	cout << "Case "  << t << ": " << ans << "\n";
  }
  return 0;
}

int dfs(int u) {
	visited[u] = true;
	length[u] = 0;
	if(!visited[graph[u]]) {
		length[u] += (dfs(graph[u]) + 1);
	}
	visited[u] = false;
	return length[u];
}
