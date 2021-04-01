#include<iostream>
using namespace std;

typedef long long LL;

LL pmi(int a, int b, int p){
    LL res = 1;
    while(b){
        if(b&1){
            res = (LL)res * a % p;
        }
        a = (LL) a * a % p;
        b >>=1;
    }
    return res;
}

int main(){
    int n ;    
    scanf("%d",&n);
    while(n -- ){
        int a, p;
        scanf("%d%d",&a,&p);
        LL res = pmi(a, p -2 , p);
        if(a % p)  printf("%lld\n", res);
        else puts("impossible");
    }
    
}