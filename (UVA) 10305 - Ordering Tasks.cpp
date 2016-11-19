#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;
bitset <MAX> visited;
stack <int> result;
void dfs(int,vector <vector <int> >&);
int main() {
	cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n,m,u,v;
  while(cin >> n >> m) {
  	if(!(n || m)) break;
  	vector <vector <int> > Graph(n+1);
  	visited.reset();
  	while(m--) {
  		cin >> u >> v;
  		Graph[u].push_back(v);
  	}
  	for(int i=1;i<=n;i++) 
  		if(!visited[i]) 
  			dfs(i,Graph);
  	while((int)(result.size()) > 1) {
  		cout << result.top() << " ";
  		result.pop();
  	}
  	cout << result.top() <<"\n";
  	result.pop();
  }
  return 0;
}
void dfs(int u,vector <vector <int> >& Graph) {
	visited[u] = true;
	for(int i=0;i<Graph[u].size();i++) {
		if(!visited[Graph[u][i]]) dfs(Graph[u][i],Graph);
	}
	result.push(u);
}
