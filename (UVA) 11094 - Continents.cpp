#include <bits/stdc++.h>
using namespace std;
char _map[20][20];
bool visited[20][20];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int bfs(bool,int,int,int,int,char,char);
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int m,n,x,y;
  char land,water;
  vector<char> regions;
  while(cin >> m >> n) {
  	for(int i=0;i<m;i++) {
  		for(int j=0;j<n;j++) {
  			cin >> _map[i][j];
  			visited[i][j] = false;
  			if(regions.size() == 0) 
  				regions.push_back(_map[i][j]);
  			if(regions.size() == 1) 
  				if(regions[0] != _map[i][j]) 
  					regions.push_back(_map[i][j]);
  		}
  	}
  	cin >> x >> y;
  	land = _map[x][y];
  	int f,_max;
  	for(int i=0;i<2;i++) if(regions[i] == land) f = i;
  	water = regions[1-f];
  	bfs(1,m,n,x,y,land,water);
  	_max = 0;
  	for(int i=0;i<m;i++) {
  		for(int j=0;j<n;j++) {
  			if(!visited[i][j] && _map[i][j] == land) {
  				_max = max(_max,bfs(0,m,n,i,j,land,water));
  			}
  		}
  	}
  	cout << _max << "\n";
  }
  return 0;
}
int bfs(bool flag, int m,int n,int x,int y, char land, char water) {
	int lands = 0;
	queue <pair <int,int> > q;
	visited[x][y] = true;
	if(flag) _map[x][y] = water;
	q.push(make_pair(x,y));
	while(!q.empty()) {
		lands++;
		pair <int,int> p = q.front();
		q.pop();
		for(int k=0;k<4;k++) {
			int i = dx[k] + p.first; 
			int j = dy[k] + p.second; 
			if(i >= 0 && i < m && j >= 0 && j < n) {
				if(!visited[i][j] && _map[i][j] == land) {
					visited[i][j] = true;
					if(flag) _map[i][j] = water;
					q.push(make_pair(i,j));
				}
			}
		}
		if(p.second == 0) {
			if(!visited[p.first][n-1] && _map[p.first][n-1] == land) {
				visited[p.first][n-1] = true;
				if(flag) _map[p.first][n-1] = water;
				q.push(make_pair(p.first,n-1));
			}
		}
		if(p.second == n-1) {
			if(!visited[p.first][0] && _map[p.first][0] == land) {
				visited[p.first][0] = true;
				if(flag) _map[p.first][0] = water;
				q.push(make_pair(p.first,0));
			}
		}
	}
	return lands;
}
