#include <bits/stdc++.h>
using namespace std;
struct Punto {
  int i;
  int j;
  int distancia;
};
int di[] = {0,0,1,-1};
int dj[] = {1,-1,0,0};
const int ORIGEN = 501;
const int MAX = 1001;
char mapa[MAX][MAX];
int distancia[MAX][MAX];
void mapea(int,int,char);
int bfs();
int main() {
  int xf,yf,n,x,y;
  for(int i=0;i<MAX;i++) {
    for(int j=0;j<MAX;j++) {
      distancia[i][j] = (1<<30);
      mapa[i][j] = '.';
    }
  }
  cin >> xf >> yf >> n;
  mapea(xf,yf,'*');
  for(int i=0;i<n;i++) {
    cin >> x >> y;
    mapea(x,y,'#');
  }
  cout << bfs() << "\n";
  return 0;
}

void mapea(int x, int y, char c) {
  mapa[ORIGEN - y - 1][ORIGEN + x - 1] = c;
}

int bfs() {
  queue <Punto> q;
  Punto inicio;
  inicio.i = ORIGEN - 1;
  inicio.j = ORIGEN - 1;
  inicio.distancia = 0;
  q.push(inicio);
  while(!q.empty()) {
    Punto actual = q.front();
    q.pop();
    if(mapa[actual.i][actual.j] == '*') return actual.distancia;
    for(int k=0;k<4;k++) {
      int ii = di[k] + actual.i;
      int jj = dj[k] + actual.j;
      if(ii >= 0 && jj >= 0 && ii < MAX && jj < MAX && mapa[ii][jj] != '#' && actual.distancia + 1 < distancia[ii][jj]) {
        Punto nuevo;
        nuevo.i = ii;
        nuevo.j = jj;
        nuevo.distancia = actual.distancia + 1;
        distancia[ii][jj] = nuevo.distancia;
        q.push(nuevo);
      }
    }
  }
}
