#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0);
  ios_base::sync_with_stdio(0);
  int L;
  string pointed,direction;
  while(1) {
  	cin >> L;
  	if(L == 0) break;
  	L--;
  	pointed = "+x";
  	while(L--) {
  		cin >> direction;
  		if(direction == "No") continue;
  		if(pointed[1] == direction[1]) {
  			if((pointed == "-x" && direction == "-x") ||
  				 (pointed == "-y" && direction == "+y") ||
  				 (pointed == "+y" && direction == "-y") ||
  				 (pointed == "-z" && direction == "+z") ||
  				 (pointed == "+z" && direction == "-z")) {
  					pointed = "+x";
  			} else pointed = "-x";
  		}
  		else if(pointed[1] == 'x' && direction[1] == 'y') {
  			if(pointed[0] == direction[0]) pointed = "+y";
  			else pointed = "-y";
  		} else if((pointed[1] == 'x' && direction[1] == 'z') ||
  				 			(pointed[1] == 'z' && direction[1] == 'x')) {
  			if(pointed[0] == direction[0]) pointed = "+z";
  			else pointed = "-z";
  		}
  	}
  	cout << pointed << "\n";
  }
}
