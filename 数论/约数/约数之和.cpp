#include <iostream>
#include <unordered_map>
using namespace std;

const int MOD = 1e9 + 7;
typedef long long LL;
int n;
unordered_map<int, int> primes;

int main(){
    scanf("%d",&n);
    while(n--){
        int x;
        scanf("%d", &x);
        for(int i = 2 ; i <= x/i ; i++){
            while(x % i == 0){
                x /= i ;
                primes[i] ++;
            }
        }
        if(x > 1) primes[x] ++;
    }
    LL res = 1;
    for(auto x : primes){
        int p = x.first, m = x.second;
        LL t = 1;
        while(m --) t = (t * p + 1) % MOD;
        res = res * t % MOD;
    }
    printf("%lld", res);
    return 0;
}