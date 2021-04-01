#include<iostream>
#include<string.h>
using namespace std;

const int N = 510, M = 100010;
int d[N][N], dist[M], n, m, x, y, z;
bool st[N];


int dijkstra(int u){
    memset(dist, 0x3f, sizeof dist);
    dist[u] =0;
    for(int i = 0; i<n;i++){
        int t = -1;
        for(int j = 1;j<=n;j++){
           if(!st[j] && ((t == -1) || dist[t] > dist[j])) 
                t = j;
        }
        
        st[t] =true;
        
        for(int j=1;j<=n;j++){
            dist[j] = min(dist[j],dist[t] + d[t][j]);
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}

int main(){
    memset(d, 0x3f, sizeof d);
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i < m ;i ++){
        scanf("%d%d%d",&x,&y,&z);
        d[x][y] = min(d[x][y],z);
    }
    int res = dijkstra(1);
    printf("%d",res);
    return 0;
}