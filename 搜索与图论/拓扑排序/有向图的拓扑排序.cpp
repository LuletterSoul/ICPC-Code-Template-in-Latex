#include <iostream>
#include <string.h>
using namespace std;

const int N = 100010, M = 100010;
int idx=0,el[M],ne[M],h[N],x,y,n,m,degree[N];
int q[M], hh = 0, tt= -1;

void insert(int x, int y){
    el[idx] = y, ne[idx] = h[x], h[x] = idx ++;
}

int topsort(){
    for(int i = 1 ; i <= n ; i++){
        if(!degree[i]) q[++tt] = i;
    }
    while(hh<=tt){
        int t = q[hh++];
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = el[i];
            --degree[j];
            if(!degree[j]){
               q[++tt] = j; 
            }
        }
    }
    return tt == n-1;
}

int main(){
    memset(h,-1,sizeof(h));
    memset(degree,0,sizeof(degree));
    scanf("%d%d",&n,&m);
    for(int i = 0; i < m; i++){
        scanf("%d%d",&x,&y);
        insert(x,y);
        ++degree[y];
    }
    if(topsort()){
        for(int i = 0; i<=tt;i++){
            printf("%d ", q[i]);
        }
    }
    else{
        printf("%d",-1);
    }
}

