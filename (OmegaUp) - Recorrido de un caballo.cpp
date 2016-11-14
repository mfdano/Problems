#include <bits/stdc++.h>
using namespace std;
struct Punto {
  int x;
  int y;
  int distancia;
};
const int MAX = 100;
int distancia[MAX+1][MAX+1];
int bfs(int,int,int,int,int,int,int,int);
int main() {
  int xf,yf,m,n,xi,yi,p,q;
  for(int i=0;i<=MAX;i++) {
    for(int j=0;j<=MAX;j++) {
      distancia[i][j] = (1<<30);
    }
  }
  cin >> m >> n >> xi >> yi >> xf >> yf >> p >> q;
  cout << bfs(m,n,xi,yi,xf,yf,p,q) << "\n";
  /*
  for(int i=1;i<=m;i++) {
    for(int j=1;j<=n;j++) {
      cout << distancia[i][j] << " ";
    }
    cout << "\n";
  }
  */
  return 0;
}

int bfs(int m,int n,int xi,int yi,int xf,int yf,int p,int q) {
  int dx[] = {p,-p,-p,p,q,-q,q,-q};
  int dy[] = {q,-q,q,-q,p,-p,-p,p};
  queue <Punto> Q;
  Punto inicio;
  inicio.x = xi;
  inicio.y = yi;
  inicio.distancia = 0;
  Q.push(inicio);
  distancia[inicio.y][inicio.x] = 0;
  while(!Q.empty()) {
    Punto actual = Q.front();
    Q.pop();
    if(actual.x == xf && actual.y == yf) return actual.distancia;
    for(int k=0;k<8;k++) {
      int x = dx[k] + actual.x;
      int y = dy[k] + actual.y;
      if(x >= 1 && y >= 1 && x <= n && y <= m && actual.distancia + 1 < distancia[y][x]) {
        Punto nuevo;
        nuevo.x = x;
        nuevo.y = y;
        nuevo.distancia = actual.distancia + 1;
        distancia[y][x] = nuevo.distancia;
        Q.push(nuevo);
      }
    }
  }
  return -1;
}
