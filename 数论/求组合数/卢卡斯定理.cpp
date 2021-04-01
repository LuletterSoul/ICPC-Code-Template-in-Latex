#include<iostream>
using namespace std;

typedef long long LL;

LL qmi(LL a ,LL k, LL p){
    LL res = 1;
    while(k){
       if(k & 1)  res = (LL) res * a % p;
       a = (LL) a * a % p;
       k >>= 1;
    }
    return res;
}

LL C(LL a, LL b, LL p){
    LL res = 1;
    for(int i = 1, j = a ; i <= b; i++, j--){
        res = (LL)res * j % p; 
        res = (LL) res * qmi(i, p-2 ,p) % p;
    }
    return res;
}

LL lucica(LL a, LL b, LL p){
   if(a < p && b < p) return C(a,b,p); 
   return C(a % p, b % p, p) * lucica(a / p, b / p, p) % p;
}

int main(){
    int n;
    LL a,b,p;
    scanf("%d", &n);
    while(n--){
        scanf("%lld%lld%lld", &a,&b,&p);
        printf("%lld\n", lucica(a,b,p));
    }
}
