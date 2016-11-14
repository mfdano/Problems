#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
void getSieveFactors();
bool isPrime(int);
int numFactors(int);
int factors[MAX];
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  getSieveFactors();
  int a,b,count;
  cin >> a >> b;
  count = 0;
  for(int i=a;i<=b;i++) {
    if(isPrime(numFactors(i))) count++;
  }
  cout << count <<"\n";
  return 0;
}
void getSieveFactors() {
  factors[0] = factors[1] = 1;
  for(int i=2;i<MAX;i++) factors[i] = i;
  for(int i=2;i*i<=MAX;i++) {
    if(factors[i] == i) {
      for(int j=i*i;j<=MAX;j+=i) factors[j] = i;
    }
  }
}

bool isPrime(int n) {
  if(n < 2) return false;
  for(int i=2;i<=sqrt(n);i++) {
    if(n%i == 0) return false;
  }
  return true;
}

int numFactors(int n) {
  if(n <= 1) return 0;
  return numFactors(n/factors[n]) + 1;
}
