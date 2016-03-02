#include <iostream>
using namespace std;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int test,n,wall1,wall2,low,high;
    cin >> test;
    for(int i=1;i<=test;i++) {
        low = high = 0;
        cin >> n;
        for(int j=0;j<n;j++) {
            if(j == 0) {
                cin >> wall2;
                continue;
            }
            wall1 = wall2;
            cin >> wall2;
            if(wall1 > wall2) low++;
            if(wall1 < wall2) high++;
        }
        cout << "Case " << i << ": " << high << " " << low << "\n";
    }
    return 0;
}
