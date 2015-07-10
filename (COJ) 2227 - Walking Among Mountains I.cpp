#include <iostream>
#include <algorithm>
#define MAX 11
using namespace std;
char map[MAX][MAX];
int DP[MAX][MAX];
int x,y,n;
int dp(int,int);
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin >> map[i][j];
			DP[i][j] = -1;
		}
	}
	cin >> x >> y;
	cout << dp(0,0) << "\n";
	return 0;
}
int dp(int i,int j) {
	if(i == x-1 && j == y-1) return 0;
	if(i > x-1 && j > y-1) return (1<<30);
	if(DP[i][j] != -1) return DP[i][j];
	int forward = ((map[i][j] - '0') - (map[i][j+1] - '0') >= 0) ? 0 : abs((map[i][j] - '0') - (map[i][j+1] - '0'));
	int down = ((map[i][j] - '0') - (map[i+1][j] - '0') >= 0) ? 0 : abs((map[i][j] - '0') - (map[i+1][j] - '0'));
	if(i < x-1 && j >= y-1) return DP[i][j] = dp(i+1,j) + down;
	if(i >= x-1 && j < y-1) return DP[i][j] = dp(i,j+1) + forward;
	return DP[i][j] = min(dp(i+1,j) + down,dp(i,j+1) + forward);
}
