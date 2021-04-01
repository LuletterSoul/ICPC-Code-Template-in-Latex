#include<iostream>
#include<string.h>
using namespace std;

const int N  = 510, M = 10010;
int n,m,k,dist[N],backup[N];

struct Edge{
    int x,y,w;
}edges[M];

int bellman_ford(int u ){
    memset(dist,0x3f,sizeof dist);
    dist[u] = 0;
    for(int i = 0 ; i< k; i++){
        memcpy(backup,dist,sizeof backup);
        for(int j = 0; j < m; j++){
            int x = edges[j].x,y = edges[j].y, w= edges[j].w;
            dist[y] = min(dist[y], backup[x] + w);
        }
    }
    if(dist[n] > 0x3f3f3f3f / 2) return -1;
    return dist[n];
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0 ; i < m ; i++){
        scanf("%d%d%d",&edges[i].x,&edges[i].y,&edges[i].w);
    }
    int res = bellman_ford(1);
    if(res == -1) printf("impossible");
    else printf("%d", res);
    return 0;
}