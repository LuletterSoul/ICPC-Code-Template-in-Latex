#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

const int N = 150010,M = 150010;

typedef pair<int,int> PII;
int dist[N],el[M],ne[M],w[M],h[N],n,m,x,y,z,idx=0;
bool st[N];
priority_queue<PII,vector<PII>,greater<PII>> q;

void add(int x, int y, int z){
    el[idx] = y, w[idx] = z, ne[idx] = h[x], h[x] = idx++;
}

int dijkstra(int u){
    memset(dist, 0x3f, sizeof dist);
    dist[u] = 0;
    q.push({dist[u], u});
    while(q.size()){
        auto t = q.top();
        q.pop();
        int ver = t.second, d = t.first;
        if(st[ver]) continue;
        st[ver] = true;
        for(int i = h[ver]; i != -1; i = ne[i]){
            int y = el[i];
            if(dist[y] > d + w[i]){
                dist[y] = d + w[i];
                q.push({dist[y],y});
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
    
}

int main(){
    scanf("%d%d",&n,&m);
    memset(h, -1, sizeof h);
    for(int i = 0; i < m;i++){
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
    }
    printf("%d",dijkstra(1));
}