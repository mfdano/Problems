#include <cstdio>
int main() {
	int n,a,b,c,middle;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d %d %d",&a,&b,&c);
		if((a > b && a < c) || (a > c && a < b)) middle = a; 
		if((b > a && b < c) || (b > c && b < a)) middle = b; 
		if((c > b && c < a) || (c > a && c < b)) middle = c;
		printf("Case %d: %d\n",i,middle); 
	}
	return 0;
}
