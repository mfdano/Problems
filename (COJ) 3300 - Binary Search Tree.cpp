#include <cstdio>
#include <algorithm>
#define MAX 105
using namespace std;
double probability[MAX];
double DP[MAX][MAX][MAX];
double dp(int,int,int);
int main() {
     int n;
     while(scanf("%d",&n) != EOF) {
          for(int i=0;i<n;i++) scanf("%lf",&probability[i]);
          for(int i=0;i<=n;i++) {
               for(int j=0;j<=n;j++) {
                    for(int k=0;k<=n;k++) {
                         DP[i][j][k] = -1;
                    }
               }
          }
          printf ("%.4lf\n",dp(0,n-1,1));
     }
     return 0;
}
double dp(int a,int b,int level) {
     if(b < a) return 0;
     if(a == b) return probability[a]*((double)level);
     if(DP[a][b][level] != -1) return DP[a][b][level];
     else {
          double best = dp(a,a-1,level+1) + dp(a+1,b,level+1) + probability[a]*((double)level);
          for(int i=a+1;i<=b;i++) {
               best = min(best,dp(a,i-1,level+1) + dp(i+1,b,level+1) + probability[i]*((double)level));
          }
          return DP[a][b][level] = best;
     }
}
