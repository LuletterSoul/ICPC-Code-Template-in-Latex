#include<iostream>
#include<unordered_map>
using namespace std;
const int MOD = 1e9+7;
typedef long long LL;
unordered_map<int,int> primes;
int n = 0;

int main(){
    scanf("%d",&n);
    LL res = 1;
    while(n--){
        int x;
        scanf("%d",&x);
        for(int i = 2 ; i <= x / i ; i++){
            while(x % i == 0){
               x /= i; 
               primes[i]++;
            }
        }
        if( x > 1) primes[x] ++; 
    }
    for(auto p : primes) res = res * (p.second + 1) % MOD;
    printf("%lld\n", res);
    return 0;
    
}
