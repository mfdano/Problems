#include <bits/stdc++.h>
using namespace std;
void dfs(vector <vector <int> >&, vector<int>&, int);
int main() {
	cin.tie(0);
  ios_base::sync_with_stdio(0);
  int test,u,v;
  string edge,nodes;
  cin >> test;
  while(test--) {
  	vector <vector <int> > graph(26);
  	vector <int> visited(26,0);
  	while(1) {
  		cin >> edge;
  		if(edge[0] == '*') break;
  		u = edge[1] - 65;
  		v = edge[3] - 65;
  		graph[u].push_back(v);
  		graph[v].push_back(u);
  	}
  	cin >> nodes;
  	int trees = 0, acorns = 0;
  	for(int i=0;i<nodes.size();i+=2) {
  		u = nodes[i] - 65;
  		if(visited[u] == 0) {
  			dfs(graph,visited,u);
  			trees++;
  		}
  		if(graph[u].size() == 0) acorns++;
  	}
  	cout << "There are " <<(trees - acorns) << " tree(s) and " << acorns << " acorn(s).\n";
  }
  return 0;
}

void dfs(vector <vector <int> >& graph, vector<int>& visited, int idx) {
	visited[idx] = 1;
	for(int i=0;i<graph[idx].size();i++) {
		if(visited[graph[idx][i]] == 0) dfs(graph,visited,graph[idx][i]);
	}
}
