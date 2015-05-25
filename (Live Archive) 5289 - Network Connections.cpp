#include <cstdio>
#include <iostream>
using namespace std;
int root[10000000];
void init(int);
int find(int);
bool joined(int,int);
void join(int,int);
int main() {
	int test,ncomputers,a,b,successful,unsuccessful;
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
			a = line[2] - '0';
			b = line[4] - '0';
			form = line[0];
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
	for(int i=0;i<n;i++) root[i] = i;
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
