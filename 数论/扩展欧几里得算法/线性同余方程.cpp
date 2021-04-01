/*
         a * x === b % m
     ==> ax = my + b
     ==> ax - my = b
     ==> ax + my'= b
         gcd(a, m) | b 则有解
      x = x0 * b / d % m        相当于倍增
*/
#include<bits/stdc++.h>
using namespace std;

using LL = long long;

int exgcd(int a, int b, int & x, int & y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    int n;
    cin >> n;
    while (n -- ) {
        int a, b, m;
        cin >> a >> b >> m;
        int x, y;
        int d = exgcd(a, m, x, y);
        if (b % d) cout << "impossible" << endl;
        else cout << (LL)b / d * x % m << endl;
    }
}