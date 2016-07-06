#include <bits/stdc++.h>
using namespace std;
string mapea(string);
map <char,char>  keypad;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int test,n,idx,total;
  string word;
  keypad['A'] = '2'; keypad['B'] = '2'; keypad['C'] = '2';
  keypad['D'] = '3'; keypad['E'] = '3'; keypad['F'] = '3';
  keypad['G'] = '4'; keypad['H'] = '4'; keypad['I'] = '4';
  keypad['J'] = '5'; keypad['K'] = '5'; keypad['L'] = '5';
  keypad['M'] = '6'; keypad['N'] = '6'; keypad['O'] = '6';
  keypad['P'] = '7'; keypad['R'] = '7'; keypad['S'] = '7';
  keypad['T'] = '8'; keypad['U'] = '8'; keypad['V'] = '8';
  keypad['W'] = '9'; keypad['X'] = '9'; keypad['Y'] = '9';

  cin >> test;
  while(test--) {
    map <string,int>  mapa;
    cin >> n;
    idx = 0; total = 0;
    for(int i=0;i<n;i++) {
      cin >> word;
      word = mapea(word);
      if(mapa.find(word) != mapa.end()) {
        mapa[word]++;
        total++;
      }
      else {
        mapa[word] = 0;
      }
    }
    if(total == 0) {
      cout << "No duplicates.\n";
    } else {
      for(auto it : mapa) {
        if(mapa[it.first] > 0) cout << it.first << " " << mapa[it.first] + 1<< "\n";
      }
    }
    if(test > 0) cout << "\n";
  }
  return 0;
}

string mapea(string number) {
  string nuevo = "";
  int idx = 0,len = 0;
  while(len < 3) {
    if(number[idx] == '-') {
      idx++;
      continue;
    }
    if(isdigit(number[idx])) {
      nuevo += (number[idx]);
      idx++;
      len++;
      continue;
    } else {
      nuevo += (keypad[toupper(number[idx])]);
      idx++;
      len++;
    }
  }
  nuevo += '-';
  while(len < 7) {
    if(number[idx] == '-') {
      idx++;
      continue;
    }
    if(isdigit(number[idx])) {
      nuevo += (number[idx]);
      idx++;
      len++;
      continue;
    } else {
        nuevo += (keypad[toupper(number[idx])]);
        idx++;
        len++;
    }
  }
  return nuevo;
}
