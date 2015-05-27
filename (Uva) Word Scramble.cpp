#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	string line,word;
	int size,szw;
	while(getline(cin,line)) {
		size = line.size();
		word = "\0";
		for(int i=0;i<size;i++) {
			if(line[i] == ' ') {
				szw = word.size();
				for(int j=szw-1;j>=0;j--) printf("%c",word[j]);
				printf(" ");
				word = "\0";
			} else word += line[i];
		}
		for(int j=size-1;j>=0;j--) {
			if(line[j] == ' ') {
				printf("\n");
				break;
			}
			else printf("%c",line[j]);
		}
	}
	return 0;
}
