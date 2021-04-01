#include<iostream>
#include<string.h>
using namespace std;

const int N = 510, M = 1e5 + 10;
int n1,n2,m,x,y,match[N],el[M], ne[M], h[N], idx=0;
bool st[N];
void add(int x, int y){
    el[idx] = y, ne[idx] = h[x], h[x] = idx ++;
}


bool find(int u){
    for(int i = h[u];i!=-1;i=ne[i]){
        int j = el[i];
        if(!st[j]){
            st[j] = true;
            if(match[j] == 0 || find(match[j])){
                match[j] = u;
                return true;
            }
        }
    }
    return false;
}

int main(){
    memset(h, -1, sizeof h);
    scanf("%d%d%d",&n1, &n2, &m);
    for(int i = 0 ; i < m; i++){
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    
    int res = 0;
    
    for(int i = 1 ; i<=n1; i++){
        memset(st, false, sizeof st);
        if(find(i)){
            res ++;
        }
    }
    printf("%d\n",res);
    return 0;
    
}