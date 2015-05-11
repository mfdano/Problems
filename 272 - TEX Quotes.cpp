#include <iostream>
#include <string>
using namespace std;
int main() {
	string line;
	int sizeline;
	bool first = true;
	while(getline(cin,line)) {
		sizeline = line.size();
		for(int i=0;i<sizeline;i++) {
			if(line[i] != '"') cout<<line[i];
			if(line[i] == '"') {
				if(first) cout<<"``";
				else cout<<"''";
				first = !first;
			}
		}
		cout<<endl;
	}
	return 0;
}
