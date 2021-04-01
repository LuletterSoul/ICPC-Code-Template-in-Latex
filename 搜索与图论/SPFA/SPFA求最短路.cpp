#include<iostream>
#include<string.h>
using namespace std;

const int N = 100010, M = 100010;
int idx=0,el[M], w[M], ne[M], h[N], dist[N], n, m, x, y, z;
int hh=0,tt=-1,q[N];
bool st[N];

void add(int x, int y, int z){
    el[idx] = y, w[idx] = z, ne[idx] = h[x], h[x] = idx++;
}

int spfa(int u){
    memset(dist, 0x3f3f3f , sizeof dist);
    dist[u] = 0;
    q[++tt] =u;
    while(hh <= tt){
        int t = q[hh++];
        st[t] = false;
        for(int i = h[t]; i!= -1; i = ne[i]){
            int j = el[i];
            if(dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                if(!st[j]){
                    q[++tt] = j;
                    st[j] = true; 
                }
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main(){
    memset(h, -1, sizeof h);
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i < m ;i++){
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
    }
    int res = spfa(1);
    if(res == -1 ) puts("impossible");
    else printf("%d",res);
}