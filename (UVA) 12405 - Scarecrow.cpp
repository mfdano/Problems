#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
	int test,n,scarecrows;
	cin >> test;
	for(int ncase=1;ncase<=test;ncase++) {
		cin >> n;
		vector <char> field(n+5);
		for(int i=0;i<n;i++) cin >> field[i];
		scarecrows = 0;
		for(int i=1;i<n;i++) {
			if(field[i-1] == '.') {
				field[i-1] = field[i] = field[i+1] = '*';
				scarecrows++;
			}
			if(i == n-1 && field[i] == '.') scarecrows++;
		}
		if(n == 1 && field[0] == '.') cout << "Case " << ncase << ": 1\n";
		else cout << "Case " << ncase << ": " << scarecrows << "\n";
	}
  return 0;
}
