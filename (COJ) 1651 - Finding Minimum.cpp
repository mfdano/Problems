#include <cstdio>
#include <algorithm>
#define MAXN 10005
#define LOGN 15
using namespace std;
int sparse[MAXN][LOGN];
int log2[MAXN];
void preprocess(int);
int query(int,int);
int input[MAXN];
int main() {
    int n,q,a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++)  {
        scanf("%d",&sparse[i][0]);
    }
    preprocess(n);
    scanf("%d",&q);
    while(q--) {
        scanf("%d %d",&a,&b);
        if(a <= b) printf("%d\n",query(a-1,b-1));
        else printf("%d\n",query(b-1,a-1));
    }
    return 0;
}
void preprocess(int n) {
    for(int i=2;i<=n;i++) log2[i] = log2[i/2] + 1;
    for(int i=0;i<=log2[n];i++) {
        for(int j=0;j<n;j++) {
            sparse[j][i+1] = min(sparse[j][i],sparse[min(j+(1<<i),n-1)][i]);
        }
    }
}
int query(int a, int b) {
    int length = log2[b - a + 1];
    return min(sparse[a][length],sparse[b - (1<<length) + 1][length]);
}
