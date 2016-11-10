#include <bits/stdc++.h>
using namespace std;
bool check(vector <int>&,vector <int>&);
int main() {
	cin.tie(0);
  ios_base::sync_with_stdio(0);
  int test,k,m;
  double val;
  char c;
  cin >> test;
  while(test--) {
  	cin >> k;
  	map <char,double> chars;
  	while(k--) {
  		cin >> c >> val;
  		chars[c] = val;
  	}
  	cin >> m;
  	string line;
  	double total = 0.0;
  	cin.ignore();
  	while(m--) {
  		getline(cin,line);
  		for(int i=0;i<line.size();i++) {
  			total += chars[line[i]];
  		}
  	}
  	total /= 100; 
  	cout << setprecision(2);
  	cout << fixed;
  	cout << total << "$\n";
  }
 	return 0;
}
