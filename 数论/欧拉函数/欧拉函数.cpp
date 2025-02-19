#include<iostream>
using namespace std;
const int N = 1e4 + 10;
int primes[N], n, phi[N]; 

int main(){
    scanf("%d", &n);
    while(n -- ){
        int x;
        scanf("%d", &x);
        int res = x;
        for(int i = 2 ; i <= x / i ; i++){
           if(x % i == 0){
               res = res / i * (i-1); // 防止溢出；
               while(x % i == 0) x /= i;
           } 
        }
        if( x > 1) res = res / x * (x-1);
        printf("%d\n", res);
    }
}

