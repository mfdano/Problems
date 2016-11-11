#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n,e;
  while(cin >> n) {
  	if(n == 0) break;
  	priority_queue <int, vector<int>, greater<int> > pq;
  	while(n--) {
  		cin >> e;
  		pq.push(e);
  	}
  	int result = 0,a,b;
  	while(!pq.empty()) {
  		if(pq.size() == 1) break;
  		a = pq.top(); 
  		pq.pop();
  		b = pq.top();
  		pq.pop();
  		result += (a + b);
  		if(pq.size() != 0) pq.push(a + b);
  	}
  	cout << result << "\n";
  }
 	return 0;
}
