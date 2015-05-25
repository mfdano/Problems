#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int i,j,cont,maxCycle,n;
	while(scanf("%d %d",&i,&j) != EOF) {
		maxCycle = -1;
		for(int index=min(i,j);index<=max(i,j);index++) {
			n = index;
			cont = 1;
			while(n != 1) {
				cont++;
				if(n%2 == 0) n /= 2;
				else n = (3*n) + 1;
			}
			if(cont > maxCycle) maxCycle = cont;
		}
		printf("%d %d %d\n",i,j,maxCycle);
	}
	return 0;
}
