#include<iostream>
using namespace std;

const int N = 1e6 + 10;

typedef long long LL;
int phi[N], primes[N],cnt;
bool st[N];

LL get_eulers(int n){
    phi[1] = 1;
    for(int i = 2; i <= n ; i++){
        if(!st[i]){
            primes[cnt++] = i;
            phi[i] = i -1;
        }
        for(int j = 0 ; primes[j] <= n / i ; j ++){
            int t = primes[j] * i;
            st[t] = true;
            if(i % primes[j] == 0){
                phi[t] = phi[i] * primes[j];
                break;
            }
            phi[t] = phi[i] * (primes[j] - 1);
        }
    }
    LL res = 0;
    for(int i = 1; i<=n ;i++){
        res += phi[i];
    }
    return res;
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%lld\n",get_eulers(n));
}