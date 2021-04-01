#include<iostream>
#include<string.h>
using namespace std;

const int N = 520, M = 2e105 + 10, INF = 0x3f3f3f3f;
int d[N][N], dist[N], n, m, x, y, z;
bool st[N];

int prime(){
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    for(int i = 0 ; i<n ;i++){
        int t = -1;
        for(int j = 1; j<=n ;j++){
            if(!st[j] && ((t == -1 ) || dist[t] > dist[j])){
                t = j;
            }
        }
        st[t] = true;
        if(i && dist[t] == INF) return -1;
        if(i)  res+= dist[t];
        
        for(int j = 1; j<=n; j++){
            dist[j] = min(dist[j],d[t][j]);
        }
    }
    return res;
}

int main(){
    scanf("%d%d",&n,&m);
    memset(d, 0x3f, sizeof d);
    for(int i = 0 ; i < m ;i ++){
        scanf("%d%d%d", &x, &y, &z);
        d[x][y] = d[y][x] = min(d[x][y],z);
    }
    int res = prime();
    if(res == -1) puts("impossible");
    else printf("%d", res);
}