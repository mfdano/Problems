#include <bits/stdc++.h>
using namespace std;
int binary_search(vector<int>&,int);
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n,m;
  while(cin >> n) {
  	vector <int> books(n);
  	for(int i=0;i<n;i++) cin >> books[i];
  	cin >> m;
  	sort(books.begin(),books.end());
  	int diff = 2000000,a,b;
  	for(int i=0;i<n;i++) {
  		int idx = binary_search(books,m-books[i]);
  		if(idx != -1 && idx != i) {
  			if(abs(books[idx] - books[i]) < diff) {
  				a = books[idx]; b = books[i];
  				diff = abs(books[idx] - books[i]);
  			}
  		}
  	}
  	cout << "Peter should buy books whose prices are " << min(a,b) << " and " << max(a,b) << ".\n\n";
  }
  return 0;
}
int binary_search(vector<int>& books, int k) {
	int lower = 0;
	int upper = books.size() - 1;
	int middle;
	while(lower <= upper) {
		middle = (lower + upper) / 2;
		if(k == books[middle]) return middle;
		if(k > books[middle]) lower = middle + 1;
		else upper = middle - 1;
	}
	return -1;
}
