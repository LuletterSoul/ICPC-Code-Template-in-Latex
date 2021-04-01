#include <iostream>
using namespace std;

#define N 100010

int lowbit(int x){
    return x & -x;
}

int n;

int main(){
    scanf("%d", &n);
    int x;
    for(int i = 0 ; i < n; i++ ){
        scanf("%d", &x);
        int cnt = 0;
        while(x){
            x = x - lowbit(x);
            cnt++;
        }
        printf("%d ",cnt);
    }
    return 0;
}