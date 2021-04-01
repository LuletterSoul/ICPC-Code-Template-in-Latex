#include<iostream>
using namespace std;
const int N = 110;
int m,x;
bool st[N];

bool is_prime(int x){
    if(x < 2) return false;
    for(int i = 2; i <= x/i ; i++){
        if(x % i == 0) return false;
    }
    return true;
}

int main(){
    scanf("%d", &m);
    while(m -- ){
        scanf("%d", &x);
        if(is_prime(x)) puts("Yes");
        else puts("No");
    }
}