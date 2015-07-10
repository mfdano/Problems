#include <cstdio>
int main() {
	int a1,a2,a3,a4,a5,b1,b2,b3,b4,b5;
	while(scanf("%d %d %d %d %d %d %d %d %d %d",&a1,&a2,&a3,&a4,&a5,&b1,&b2,&b3,&b4,&b5) != EOF) {
		printf("%c\n",(a1 != b1 && a2 != b2 && a3 != b3 && a4 != b4 && a5 != b5) ? 'Y' : 'N');
	}
	return 0;
}
