#include <bits/stdc++.h>
using namespace std;
bool check(vector <int>&,vector <int>&);
int main() {
	cin.tie(0);
  ios_base::sync_with_stdio(0);
  int A,B,C,X,Y;
  bool cards[53];
  while(cin >> A >> B >> C >> X >> Y) {
  	if(!(A && B && C && X && Y)) break;
  	for(int i=1;i<=52;i++) cards[i] = 1;
  	cards[A] = 0;
  	cards[B] = 0;
  	cards[C] = 0;
  	cards[X] = 0;
  	cards[Y] = 0;
  	vector <int> princess;
  	vector <int> prince;
  	princess.push_back(A);
  	princess.push_back(B);
  	princess.push_back(C);
  	prince.push_back(X);
  	prince.push_back(Y);
  	sort(princess.begin(),princess.end());
  	sort(prince.begin(),prince.end());
  	int cont = 0;
  	for(int i=0;i<3;i++) {
  		if(princess[i] > prince[0]) {
  			prince[0] = 53;
  			cont++;
  		}
  		else if(princess[i] > prince[1]) {
  			prince[1] = 53;
  			cont++;
  		}
  	}
  	if(cont == 2) cout << "-1\n";
  	else {
  		if(prince[0] != 53 && prince[1] != 53) {
  			for(int i=1;i<=52;i++) {
  				if(cards[i] == 1) {
  					cout << i << "\n";
  					break;
  				}
  			}
  		}
  		else {
  			int flag = -1;
  			prince.push_back(53);
  			for(int j=1;j<3;j++) {
  				for(int i=princess[j]+1;i<=52;i++) {
	  				if(cards[i]) {
	  					prince[1] = X;
	  					prince[2] = Y;
	  					prince[0] = i;
	  					sort(prince.begin(),prince.end());
	  					if(check(princess,prince)) {
	  						flag = i;
	  						break;
	  					}
	  				}
	  			}
	  			if(flag != -1) {
	  				cout << flag << "\n";
	  				break;
	  			}
  			}
  			if(flag == -1) cout << "-1\n";
  		}
  	}
  }
}

bool check(vector <int>& princess,vector <int>& prince) {
	int cont = 0;
  	for(int i=0;i<3;i++) {
  		if(princess[i] > prince[0]) {
  			prince[0] = 53;
  			cont++;
  		}
  		else if(princess[i] > prince[1]) {
  			prince[1] = 53;
  			cont++;
  		}
  		else if(princess[i] > prince[2]) {
  			prince[2] = 53;
  			cont++;
  		}
  	}	
  	return (cont < 2 ? true : false);
}
