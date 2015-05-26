#include <cstdio>
#include <iostream>
#include <cctype>
using namespace std;
int root[10000000];
void init(int);
int find(int);
bool joined(int,int);
void join(int,int);
int main() {
	int test,ncomputers,a,b,successful,unsuccessful,r,t;
	char form;
	string line;
	scanf("%d",&test);
	while(test--) {
		scanf("%d",&ncomputers);
		init(ncomputers);
		successful = unsuccessful = 0;
		getline(cin,line);
		while(getline(cin,line)) {
			if(line.empty()) break;
			form = line[0];
			r = 1;
			a = b = 0;
			for(int i=line.size()-1;i>1;i--) {
				if(line[i] == ' ') {
					t = i - 1;
					break;
				}
				if(isdigit(line[i])) {
					b += ((line[i] - '0') * r);
					r *= 10;
				}
			}
			r = 1;
			for(int j=t;j>0;j--) {
				if(line[j] == ' ') break;
				if(isdigit(line[j])) {
					a += ((line[j] - '0') * r);
					r *= 10;
				}
			}
			if(form == 'c') 
				join(a,b);
			else {
				if(joined(a,b)) successful++;
				else unsuccessful++;
			}
		}
		printf("%d,%d\n",successful,unsuccessful);
		if(test > 0) printf("\n");
	}
	return 0;
}
void init(int n) {
	for(int i=1;i<=n;i++) root[i] = i;
}
int find(int a) {
	return (a == root[a]) ? a : root[a] = find(root[a]);
}
bool joined(int a,int b) {
	return find(a) == find(b);
}
void join(int a,int b) {
	if(joined(a,b)) return;
	root[find(a)] = find(b);
}
