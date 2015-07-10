#include <iostream>
#include <algorithm>
#define MAX 10005
using namespace std;
int coins1[MAX];
int coins2[MAX];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
	int n,maxfinal1,maxfinal2,current_max1,current_max2,test;
	string name1,name2;
	cin >> test;
	while(test--) {
	    cin >> n;
	    cin >> name1;
	    for(int i=0;i<n;i++) cin >> coins1[i];
	    maxfinal1 = current_max1 = coins1[0];
	    cin >> name2;
	    for(int i=0;i<n;i++) cin >> coins2[i];
	    maxfinal2 = current_max2 = coins2[0];
	    for(int i=1;i<n;i++) {
		    current_max1 = max(current_max1+coins1[i],coins1[i]);
		    maxfinal1 = max(current_max1,maxfinal1);
		    current_max2 = max(current_max2+coins2[i],coins2[i]);
		    maxfinal2 = max(current_max2,maxfinal2);
	    }
	    if(maxfinal1 > maxfinal2) cout << name1 << " " << maxfinal1 << "\n";
	    if(maxfinal1 < maxfinal2) cout << name2 << " " << maxfinal2 << "\n";
	    if(maxfinal1 == maxfinal2) cout << "Tied " << maxfinal1 << "\n";
    }
    return 0;
}
