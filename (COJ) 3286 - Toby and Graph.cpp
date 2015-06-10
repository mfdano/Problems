#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 10005
using namespace std;
void dfs(int);
vector <int> graph[MAX];
int visited[MAX];
int components;
int main() {
        int n,m,a,b,test;
        scanf("%d",&test);
        while(test--) {
             components = 0;
             for(int i=1;i<=n;i++) {
                    for(int j=0;j<graph[i].size();j++) {
                            graph[i][j] = 0;
                    }
             }
             scanf("%d %d",&n, &m);
             while(m--) {
                    scanf("%d %d",&a, &b);
                    graph[a].push_back(b);
                    graph[b].push_back(a);
             }
             for(int i=1;i<=n;i++) visited[i] = 0;
             for(int i=1;i<=n;i++) {
                    if(visited[i] == 0) {
                           dfs(i);
                           components++;
                    }
             }
             printf("%lld\n",((components * (components + 1)) / 2) - components);
        }
        return 0;
}
void dfs(int u) {
        visited[u]++;
        for(int i=0;i<graph[u].size();i++) {
            int v = graph[u][i];
            if(visited[v] == 0) dfs(v);
        }
}
