#include <cstdio>
#include <iostream>
using namespace std;
int main() {
	string keyboard = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	string line;
	int j;
	while(getline(cin,line)) {
		for(int i=0;i<line.size();i++) {
			if(line[i] == ' ') printf(" ");
			for(j=0;j<48;j++) {
				if(keyboard[j] == line[i]) {
					printf("%c",keyboard[j-1]);
					break;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
