#include<iostream>
using namespace std;

const int N = 8;

int n,p[N],st[N];

void dfs(int u){
    if(u == n){
        for(int i = 0; i< n;i++) printf("%d ",p[i]);
        puts("");
    }
    
    for(int i = 1; i<=n ; i++){
        if(!st[i]){
            st[i] = true;
            p[u] = i;
            dfs(u+1);
            st[i] = false;
        }
    }
}

int main(){
    scanf("%d",&n);
    dfs(0);
}