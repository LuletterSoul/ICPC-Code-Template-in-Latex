#include<iostream>
#include<string.h>
using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;

int idx=0,el[M],ne[M],h[N],color[N],n,m,x,y;

void add(int x, int y){
    el[idx] = y, ne[idx] = h[x], h[x] = idx++;
}


bool dfs(int u, int c){
    color[u] = c;
    for(int i = h[u]; i != -1 ; i = ne[i]){
        int j = el[i];
        if(!color[j]){
            if(!dfs(j, 3-c)) return false;
        }
        else if(color[j] == c) return false;
    }
    return true;
}

int main(){
    memset(h, -1, sizeof h);
    scanf("%d%d",&n,&m);
    while(m --){
        scanf("%d%d",&x,&y);
        add(x,y),add(y,x);
    }
    
    bool flag = true;
    for(int i = 1 ; i <=n ; i++){
        if(!color[i]){
            if(!dfs(i, 1)){
                flag = false;
                break;
            }
        }
    }
    if(flag) puts("Yes");
    else puts("No");
}