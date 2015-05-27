#include <cstdio>
#include <algorithm>
#define MAX 100005
using namespace std;
struct Match {
	int a,b;
};
bool operator < (Match first, Match second) { return (first.a - first.b) > (second.a - second.b); }
int main() {
	Match match[MAX];
	int n,g,idx,a,b,points;
	while(scanf("%d %d",&n,&g) != EOF) {
		points = idx = 0;
		while(n--) {
			scanf("%d %d",&a,&b);
			if(a > b) points += 3;
			if(a == b) {
				points++;
				if(g > 0) g-- , points += 2;
			} 
			if(a < b) {
				match[idx].a = a;
				match[idx].b = b;
				idx++;
			}
		}
		if(g > 0) {
			if(g == 1) {
				if(match[0].b - match[0].a == 1) points++;
			} else {
				sort(match,match+idx);
				for(int i=0;i<idx;i++) {
					if(match[i].b - match[i].a <= g) {
						g -= (match[i].b - match[i].a);
						points++;
						if(g > 0) g-- , points += 2;
					}
				}
			}
		}
		printf("%d\n",points);
	}
	return 0;
}
