#include <bits/stdc++.h>
using namespace std;
struct position {
  int i,j,k,steps;
};
const int MAX = 100;
char labyrinth[MAX][MAX][MAX];
int min_steps[MAX][MAX][MAX];
int di[] = {0,0,1,-1};
int dj[] = {1,-1,0,0};
int dk[] = {1,-1};
int bfs(int,int,int,int,int,int,int,int,int);
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int l,w,h,i_start,j_start,k_start,i_end,j_end,k_end;
  while(cin >> l >> w >> h) {
    if(l == 0 && w == 0 && h == 0) break;
    for(int k=0;k<h;k++) {
      for(int i=0;i<l;i++) {
        for(int j=0;j<w;j++) {
          cin >> labyrinth[i][j][k];
          min_steps[i][j][k] = (1<<30);
          if(labyrinth[i][j][k] == 'S') {
            i_start = i;
            j_start = j;
            k_start = k;
          }
          if(labyrinth[i][j][k] == 'E') {
            i_end = i;
            j_end = j;
            k_end = k;
          }
        }
      }
    }
    cout << bfs(l,w,h,i_start,j_start,k_start,i_end,j_end,k_end) << "\n";
  }
  return 0;
}
int bfs(int l,int w,int h,int i_start,int j_start,int k_start,int i_end,int j_end,int k_end) {
  position start;
  start.i = i_start;
  start.j = j_start;
  start.k = k_start;
  start.steps = 0;
  queue <position> q;
  q.push(start);
  while(!q.empty()) {
    min_steps[start.i][start.j][start.k] = 0;
    position actual = q.front();
    q.pop();
    if(actual.i == i_end && actual.j == j_end && actual.k == k_end) return actual.steps;
    for(int idx=0;idx<4;idx++) {
      int ni = di[idx] + actual.i;
      int nj = dj[idx] + actual.j;
      if(ni >= 0 && nj >= 0 && ni < l && nj < w && labyrinth[ni][nj][actual.k] != '#' && actual.steps + 1 < min_steps[ni][nj][actual.k]) {
        position newp;
        newp.i = ni;
        newp.j = nj;
        newp.k = actual.k;
        newp.steps = actual.steps + 1;
        min_steps[newp.i][newp.j][newp.k] = newp.steps;
        q.push(newp);
      }
    }
    if(labyrinth[actual.i][actual.j][actual.k] == '-') {
      for(int k=0;k<2;k++) {
        int nk = dk[k] + actual.k;
        if(nk >= 0 && nk < h && labyrinth[actual.i][actual.j][nk] == '-' && actual.steps + 1 < min_steps[actual.i][actual.j][nk]) {
          position elevator;
          elevator.i = actual.i;
          elevator.j = actual.j;
          elevator.k = nk;
          elevator.steps = actual.steps + 1;
          min_steps[elevator.i][elevator.j][elevator.k] = elevator.steps;
          q.push(elevator);
        }
      }
    }
  }
  return -1;
}
