#include <cstdio>
#include <cmath>
int main() {
	long long s,n,t,p,r;
	double root;
	while(scanf("%lld",&s) != EOF) {
		if(s == 0) break;
		root = sqrt(1 + 8*s);
		r = (long long)root;
		if(root - (double)r != 0) {
			root = ceil(root);
			root--; root /= 2;
			root = ceil(root);
			n = (long long)root;
			t = (n * (n+1)) / 2;
			p = t - s;
			printf("%lld %lld\n",p,n);
		} else {
			root--; root /= 2;
			root = ceil(root);
			n = (long long)root;
			printf("%lld %lld\n",n+1,n+1);
		}
	}
	return 0;
}
