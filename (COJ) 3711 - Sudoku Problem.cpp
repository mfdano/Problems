#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int test,n;
  cin >> test;
  while(test--) {
    cin >> n;
    bool solve = true;
    int s = (int)sqrt(n);
    int board[n][n];
    int row_sum;
    int column_sum[n];
    set<int> rows_sum;
    set<int> colums[n];
    for(int i=0;i<n;i++) {
      row_sum = 0;
      set<int> rows;
      for(int j=0;j<n;j++) {
        cin >> board[i][j];
        rows.insert(board[i][j]);
        row_sum += board[i][j];
        colums[j].insert(board[i][j]);
        if(i == 0) column_sum[j] = board[i][j];
        if(i > 0) column_sum[j] += board[i][j];
      }
      if(solve) {
        if(rows.size() == n) {
          rows_sum.insert(row_sum);
        } else {
          solve = false;
        }
      }
    }
    if(rows_sum.size() != 1) solve = false;
    if(solve) {
      for(int i=0;i<n-1;i++) {
        if((column_sum[i] != column_sum[i+1]) || (colums[i].size() != colums[i+1].size())) {
          solve = false;
          break;
        }
      }
    }
    if(solve) {
      int sum_square;
      set <int> sum_squares;
      for(int i=0;i<n;i+=s) {
        sum_square = 0;
        set <int> square;
        for(int k=i;k<i+s;k++) {
          for(int l=i;l<i+s;l++) {
            sum_square += board[k][l];
            square.insert(board[k][l]);
          }
        }
        if(solve) {
          if(square.size() == n) {
            sum_squares.insert(sum_square);
          }
          else {
            solve = false;
          }
        }
      }
    }
    cout << (solve ? "yes" : "no") << "\n";
  }
  return 0;
}
