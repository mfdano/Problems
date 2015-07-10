#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 105
int table[MAX][MAX];
int DP[MAX][MAX];
int dp(int,int);
int n;
int main() {
	int l,test;
	scanf("%d",&test);
	while(test--) {
		scanf("%d",&n);
		l = 0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<=l;j++) {
				scanf("%d",&table[i][j]);
				DP[i][j] = -1;
			}
			l++;
		}
		printf("%d\n",dp(0,0));
	}
	return 0;
}
int dp(int i,int j) {
	if(i == n-1) return table[i][j];
	if(j > i) return -99999999;
	if(DP[i][j] != -1) return DP[i][j];
	return DP[i][j] = max(dp(i+1,j),dp(i+1,j+1)) + table[i][j];
}
