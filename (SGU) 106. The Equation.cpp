#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
long long gcd(long long,long long);
void extendedEuclid(long long,long long);
long long lcm(long long,long long);
long long x,y,d;
int main() {
    long long a,b,c,x1,x2,y1,y2,xo,yo,lcm_ab;
    double nx1,nx2,ny1,ny2;
    scanf("%lld %lld %lld",&a,&b,&c);
    scanf("%lld %lld",&x1,&x2);
    scanf("%lld %lld",&y1,&y2);
    if(a == 0 && b == 0) {
        if(c == 0) printf("%lld\n",((x2 - x1) +1) * ((y2 - y1) + 1));
        else printf("0\n");
    }
    else if(a == 0) {
        if(c % b == 0 && (-c / b) <= y2 && (-c / b) >= y1) printf("%lld\n",(x2 - x1) + 1);
        else printf("0\n");
    }
    else if(b == 0 && a != 0) {
        if(c % a == 0 && (-c / a) <= x2 && (-c / a) >= x1) printf("%lld\n",(y2 - y1) + 1);
        else printf("0\n");
    } else {
        extendedEuclid(a,b);
        if(c % d == 0) {
            xo = ((-1)*c*x) / d;
            yo = ((-1)*c*y) / d;
            lcm_ab = lcm(a,b);
            nx1 = (((double)x1 - (double)xo) * (double)a) / (double)lcm_ab;
            nx2 = (((double)x2 - (double)xo) * (double)a) / (double)lcm_ab;
            ny1 = (((double)yo - (double)y1) * (double)b) / (double)lcm_ab;
            ny2 = (((double)yo - (double)y2) * (double)b) / (double)lcm_ab;
            if(nx1 > nx2) swap(nx1,nx2);
            if(ny1 > ny2) swap(ny1,ny2);
            x1 = (long long)ceil(nx1);
            y1 = (long long)ceil(ny1);
            x2 = (long long)floor(nx2);
            y2 = (long long)floor(ny2);
            if(min(x2,y2) < max(x1,y1)) printf("0\n");
            else printf("%lld\n",min(x2,y2) - max(x1,y1) + 1);
        } else printf("0\n");
    }
    return 0;
}
long long gcd(long long a,long long b) {
    if(b == 0) return a;
    return gcd(b,a%b);
}
void extendedEuclid(long long a,long long b) {
    if(b == 0) { x = 1 , y = 0 , d = a; return; }
    extendedEuclid(b,a%b);
    long long x1 = y;
    long long y1 = x - (a/b) * y;
    x = x1 , y = y1;
}
long long lcm(long long a,long long b) {
    return (a / gcd(a,b)) * b;
}
