#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

typedef long long LL;

const int N = 1e5 + 10, mod = 1e9 + 7;

LL qmi(LL a, LL k, LL p){
    LL res =1;
    while(k){
        if(k & 1) res = (LL) res * a % p; 
        a = (LL) a * a % p;
        k >>= 1;
    }    
    return res;
}

int main(){
    int n;
    cin >> n;
    LL fact[N], infact[N];
    fact[0] = infact[0] = 1;
    for(int i =1 ; i < N ;i ++){
        fact[i] = fact[i-1] * i % mod;
        infact[i] = infact[i-1] * qmi(i, mod - 2, mod) % mod;
    }
    LL a, b;
    while(n--){
       cin >> a >> b; 
       cout << fact[a] * infact[b] % mod * infact[a-b] % mod << endl;
    }
    return 0;
}