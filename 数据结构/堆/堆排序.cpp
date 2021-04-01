#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;

int n,m,h[N];



void down(int u){
    int t = u;
    if(2*u<=n&&h[2*u] < h[t]) t = 2*u;
    if(2*u+1<=n&&h[2*u+1] < h[t]) t = 2*u+1;
    if(u!=t){
        swap(h[u],h[t]);
        down(t);
    }
}


int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++) scanf("%d",&h[i]);
    for(int i = n/2;i;i--){
        down(i);
    }
    while(m--){
        printf("%d ", h[1]);
        swap(h[1],h[n]);
        n--;
        down(1);
    }
    return 0;
}