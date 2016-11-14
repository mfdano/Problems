#include <bits/stdc++.h>
using namespace std;
#define MAX 2000
struct Agente {
  int i,j,dist;
};
char mapa[MAX][MAX];
int distancia[MAX][MAX];
queue<Agente> q;
int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};
int bfs(int,int);
int main() {
  //cin.tie(0);
  //ios_base::sync_with_stdio(0);
  int n,m;
  Agente agente;
  cin >> n >> m;
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cin >> mapa[i][j];
      if(mapa[i][j] == 'G') {
        agente.i = i;
        agente.j = j;
        agente.dist = 0;
        q.push(agente);
        distancia[i][j] = 0;
      }
      else distancia[i][j] = (1<<30);
    }
  }

  cout << bfs(n,m) << "\n";

  return 0;
}

int bfs(int f, int c) {
  int x,y,maxi = -1;;
  while(!q.empty()) {
    Agente actual = q.front();
    q.pop();
    for(int k=0;k<4;k++) {
       x = dx[k] + actual.i;
       y = dy[k] + actual.j;
       if(x >= 0 && x < f && y >= 0 && y < c) {
         if(mapa[x][y] == '.' && actual.dist + 1 < distancia[x][y] ) {
          Agente a;
          a.i = x;
          a.j = y;
          a.dist = actual.dist + 1;
          maxi = max(maxi,a.dist);
          distancia[x][y] = a.dist;
         	q.push(a);
         }
       }
    }  
  }
  return maxi;
}
