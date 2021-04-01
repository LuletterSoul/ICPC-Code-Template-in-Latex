#include<iostream>
using namespace std;


int main(){
    int n;
    scanf("%d",&n);
    int res = 0;
    for(int i = 1; i <= n ; i ++){
        int x;
        scanf("%d",&x);
        if(i%2)  res ^= x;
    }
    if(res) puts("Yes");
    else puts("No");
    return 0;
}