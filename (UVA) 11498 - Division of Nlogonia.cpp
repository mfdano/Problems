#include <cstdio>
int main() {
	int n,x,y,divpX,divpY;
	while(scanf("%d",&n) != EOF) {
		if(n == 0) break;
		scanf("%d %d",&divpX,&divpY);
		while(n--) {
			scanf("%d %d",&x,&y);
			if(x == divpX || y == divpY) printf("divisa\n");
			if(x > divpX && y > divpY) printf("NE\n");
			if(x < divpX && y < divpY) printf("SO\n");
			if(x < divpX && y > divpY) printf("NO\n");
			if(x > divpX && y < divpY) printf("SE\n");
		}
	}
	return 0;
}
