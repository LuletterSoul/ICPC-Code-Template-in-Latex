#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int a, int b){
    if(a < b) swap(a,b);
    return b ? gcd(b, a%b) : a;
}

int n;

int main(){
    scanf("%d",&n);
    while(n--){
        int a, b;
        scanf("%d%d",&a, &b);
        printf("%d\n", gcd(a,b));
    }
    return 0;
}