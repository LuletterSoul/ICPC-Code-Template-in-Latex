#include<iostream>
using namespace std;
const int N = 110;
int n, x;


void get_prime(int x){
    for(int i = 2; i <= x/i ; i++){
        if(x % i == 0){
            int s = 0;
            while(x % i == 0){
                x /= i;
                s++;
            }
            cout << i << ' ' << s <<endl;
        }
    }
    if(x > 1) cout << x <<' ' << 1 << endl;
    cout  << endl;
}

int main(){
    scanf("%d",&n);
    while(n --){
        scanf("%d", &x);
        get_prime(x);
    }
    return 0;
}