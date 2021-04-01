#include<iostream>
using namespace std;

int n, a, b ,p;
typedef long long LL;

LL qmi(int a,int b, int p){
    LL res = 1;
    while(b){
        if(b & 1){
            res = (LL)res * a % p;
        }
        a = (LL) a * a % p;
        b >>= 1;
    }
    return res;
}

int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d%d%d", &a, &b, &p);
        printf("%lld\n", qmi(a,b,p));
    }
}