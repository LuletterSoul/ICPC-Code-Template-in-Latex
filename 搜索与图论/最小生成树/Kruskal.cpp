#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10;
int n,m,x,y,z, p[N];

struct Edge{
    int x,y,z;
    bool operator < (const Edge &e) const{
        return z < e.z;
    }
}edges[M];

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0 ;i < m; i++){
        scanf("%d%d%d", &x, &y, &z);
        edges[i] = {x,y,z};
    }
    
    for(int i = 1; i<= N; i++) p[i] =i;
    
    sort(edges , edges + m);
    
    int cnt = 0, res = 0;
    
    for(int i = 0; i<m; i++){
        int x = edges[i].x, y = edges[i].y, z = edges[i].z;
        
        int px = find(x), py = find(y);
        
        if(px != py){
            p[px] = py;
            cnt ++;
            res += z;
        }
    }
    
    if(cnt != n-1) puts("impossible");
    else printf("%d",res);
}