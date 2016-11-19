#include <bits/stdc++.h>
using namespace std;
const int INF = (1<<30);
bool isBicolorable(vector < vector <int> >&);
int color[205];
int main() {
	cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n,l,u,v;
  while(cin >> n) {
  	if(!n) break;
  	vector < vector <int> > Graph(n);
  	cin >> l;
  	while(l--) {
  		cin >> u >> v;
  		Graph[u].push_back(v);
  		Graph[v].push_back(u);
  	}
  	for(int i=0;i<n;i++) color[i] = INF;
  	cout << (isBicolorable(Graph) ? "" : "NOT ") <<"BICOLORABLE.\n";
  }
  return 0;
}

bool isBicolorable(vector < vector <int> >& Graph) {
	queue <int> q;
	q.push(0);
	color[0] = 0;
	bool isBipartite = true;
	while(!q.empty() && isBipartite) {
		int u = q.front();
		q.pop();
		for(int i=0;i<Graph[u].size();i++) {
			if(color[Graph[u][i]] == INF) {
				color[Graph[u][i]] = 1 - color[u];
				q.push(Graph[u][i]);
			}
			else if(color[Graph[u][i]] == color[u]) {
				isBipartite = false;
				break;
			}
		}
	}
	return isBipartite;
}
