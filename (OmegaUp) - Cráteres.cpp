#include <bits/stdc++.h>
using namespace std;
#define MAX 500
int mapa[MAX][MAX];
int visitados[MAX][MAX];
int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};
int crateres;
int rocas;
void explorar(int,int,int,int);
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int f,c,idx;
  int max_rocas;
  cin >> f >> c;
  for(int i=0;i<f;i++) {
    for(int j=0;j<c;j++) {
      cin >> mapa[i][j];
      visitados[i][j] = 0;
    }
  }
  crateres = 0;
  max_rocas = -1;
  for(int i=0;i<c;i++) {
    for(int j=0;j<f;j++) {
      if(visitados[j][i] == 0 && mapa[j][i] > 0) {
        crateres++;
        rocas = 0;
        explorar(j,i,f,c);
        if(rocas > max_rocas) {
          max_rocas = rocas;
          idx = crateres;
        }
      }
    }
  }
  if(crateres == 0) cout << "0 0\n";
  else cout << idx << " " << max_rocas << "\n";
  return 0;
}

void explorar(int i, int j,int f, int c) {
  int x,y;
  queue< pair<int,int> > q;
  q.push(make_pair(i,j));
  while(!q.empty()) {
    pair<int,int> actual = q.front();
    q.pop();
    if(visitados[actual.first][actual.second] == 0) {
      rocas += mapa[actual.first][actual.second];
      visitados[actual.first][actual.second] = crateres;
      for(int k=0;k<4;k++) {
        x = dx[k] + actual.first;
        y = dy[k] + actual.second;
        if(x >= 0 && x < f && y >= 0 && y < c) {
          if(visitados[x][y] == 0 && mapa[x][y] > 0) {
            q.push(make_pair(x,y));
          }
        }
      }
    }
  }
}
