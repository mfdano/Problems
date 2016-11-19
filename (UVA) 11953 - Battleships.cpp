#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;
char grid[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void bfs(int,int,int);
int main() {
	cin.tie(0);
  ios_base::sync_with_stdio(0);
  int test,n,ans;
  cin >> test;
  for(int t=1;t<=test;t++) {
  	cin >> n;
  	for(int i=0;i<n;i++) {
  		for(int j=0;j<n;j++) {
  			cin >> grid[i][j];
  			visited[i][j] = false;
  		}
  	}
  	ans = 0;
  	for(int i=0;i<n;i++) {
  		for(int j=0;j<n;j++) {
  			if(!visited[i][j] && (grid[i][j] == 'x')) {
  				bfs(n,i,j);
  				ans++;
  			}	
  		}
  	}
  	cout << "Case " << t << ": " << ans << "\n";
  }
  return 0;
}
void bfs(int n,int i,int j) {
	queue <pair <int,int> > q;
	q.push(make_pair(i,j));
	visited[i][j] = true;
	while(!q.empty()) {
		pair <int,int> p = q.front();
		q.pop();
		for(int k=0;k<4;k++) {
			int di = p.first + dx[k];
			int dj = p.second + dy[k];
			if(di < n && dj < n && di >= 0 && dj >= 0) {
				if((grid[di][dj] == '@' || grid[di][dj] == 'x') && !visited[di][dj]) {
					q.push(make_pair(di,dj));
					visited[di][dj] = true;
					break;
				}
			}
		}
	}
}
