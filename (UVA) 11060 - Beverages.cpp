#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;
vector <int> indegree(MAX);
void topological_sort(int,int,vector < vector <int> >&,map <int,string>&);
int main() {
	cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n,m,ncase;
  string beverage,u,v;
  ncase = 1;
  while(cin >> n) {
  	map <string,int> beverages;
  	map <int,string> ids;
  	for(int i=0;i<n;i++) {
  		cin >> beverage;
  		beverages[beverage] = i;
  		ids[i] = beverage;
  	}
  	vector < vector <int> > Graph(n);
  	for(int i=0;i<n;i++) indegree[i] = 0;
  	cin >> m;
  	while(m--) {
  		cin >> u >> v;
  		Graph[beverages[u]].push_back(beverages[v]);
  		indegree[beverages[v]]++;
  	}
  	topological_sort(n,ncase,Graph,ids);
  	ncase++;
  }
  return 0;
}
void topological_sort(int n, int ncase,vector < vector <int> >& Graph,map <int,string>& beverages) {
	priority_queue < int, vector<int>, greater<int> > q;
	vector <int> ts;
	for(int i=0;i<n;i++) 
		if(indegree[i] == 0) 
			q.push(i);
	while(!q.empty()) {
		int u = q.top();
		q.pop();
		ts.push_back(u);
		for(int i=0;i<Graph[u].size();i++) {
			indegree[Graph[u][i]]--;
			if(indegree[Graph[u][i]] == 0) {
				q.push(Graph[u][i]);
			}
		}
	}
	cout << "Case #" << ncase << ": Dilbert should drink beverages in this order: "; 
	for(int i=0;i<n-1;i++) cout << beverages[ts[i]] << " ";
	cout << beverages[ts[n - 1]] << ".\n\n";
}
