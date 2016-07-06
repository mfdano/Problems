#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n,sz;
  string word;
  cin >> n;
  int i = 0;
  while(n--) {
    stack <char> s;
    getline(cin,word);
    if(i == 0) {
      getline(cin,word);
      i++;
    }
    sz = word.size();
    if(sz == 0) cout << "Yes\n";
    else {
      for(int i=0;i<sz;i++) {
        if(word[i] == '(' || word[i] == '[') {
          s.push(word[i]);
        } else {
          if(word[i] == ')') {
            if(!s.empty()) {
              if(s.top() == '(') {
                s.pop();
              }
            } else {
              s.push(word[i]);
            }
          }
          if(word[i] == ']') {
            if(!s.empty()) {
              if(s.top() == '[') {
                s.pop();
              }
            } else {
              s.push(word[i]);
            }
          }
        }
      }
      if(s.empty() || sz == 0) cout << "Yes\n";
      else cout << "No\n";
    }
  }
  return 0;
}
