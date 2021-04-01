#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int N = 100010, M = 100010;
int n,m,h[N],el[N], ne[M], idx=0, x, y ,d[N];
queue<int> q;


void insert(int x, int y){
    el[idx] = y, ne[idx] = h[x], h[x] = idx ++;
}

int bfs(int u){
    q.push(u);
    memset(d, -1, sizeof(d));
    d[u] = 0;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i = h[t]; i!=-1 ; i = ne[i]){
            if(d[el[i]] == -1){
                d[el[i]] = d[t] + 1;
                q.push(el[i]);
            }
        }
    }
    return d[n];
}

int main(){
    scanf("%d%d",&n,&m);    
    memset(h, -1,sizeof(h));
    for(int i = 0 ; i < m ; i++){
        scanf("%d%d",&x,&y);
        insert(x,y);
    }
    printf("%d", bfs(1));
}