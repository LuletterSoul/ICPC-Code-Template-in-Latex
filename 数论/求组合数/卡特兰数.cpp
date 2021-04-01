#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const LL mod = 1e9 + 7;


typedef long long LL;


LL qmi(LL a, LL k, LL p){
    LL res = 1;
    while(k){
        if(k & 1)  res = (LL) res * a % p ;
        a = (LL) a * a % p;
        k >>= 1;
    }
    return res;
}

int main(){
    int n;
    scanf("%d", &n);
    int a = 2 *n, b = n;
    LL res =1 ;
    for(int i = a; i > a- b ; i--) res = (LL) res * i % mod;
    for(int i = 1; i <= b ; i++) res = (LL) res * qmi(i, mod - 2, mod) % mod;
    res = (LL) res * qmi(n+1, mod - 2, mod) % mod;
    printf("%lld\n",res);
    scanf("%d", &n);
    
}