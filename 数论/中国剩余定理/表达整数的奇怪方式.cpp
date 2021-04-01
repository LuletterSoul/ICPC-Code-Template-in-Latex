#include<iostream>
using namespace std;

typedef long long LL;

LL exgcd(LL a, LL b, LL &x, LL &y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    LL d = exgcd(b, a%b, y, x);
    y -= (a/b) * x;
    return d;
}

int main(){
    int n;
    LL a1,m1;
    scanf("%d",&n);
    scanf("%lld%lld", &a1, &m1);
    bool has_ans = true;
    for(int i = 0 ; i < n - 1 ;i++){
        LL a2,m2,k1,k2;
        scanf("%lld%lld", &a2, &m2);
        LL d = exgcd(a1,a2,k1,k2);
        if((m2-m1) % d){
            has_ans = false;
            break;
        }
        int t = a2 / d;
        k1 *= (m2-m1) / d;
        k1 = (k1 % t + t) % t;
        
        m1 = a1 * k1 + m1;
        a1 = abs(a1 / d * a2);
    }
    if(has_ans) printf("%lld\n", (m1 % a1 + a1) % a1);
    else printf("%d\n",-1);
    return 0;
}
