#include<iostream>
using namespace std;

const int N = 1e6 +10;
int primes[N];
bool st[N];
int cnt;

void get_primes(int n){
    for(int i = 2; i <= n ; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0 ; primes[j] <= n/i ; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    get_primes(n);
    printf("%d\n",cnt);
}