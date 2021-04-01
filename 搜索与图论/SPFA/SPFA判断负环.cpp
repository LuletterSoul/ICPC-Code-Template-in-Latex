#include <iostream>
#include<string.h>
#include <queue>
using namespace std;

const int N = 100010, M = 100010;

int n,m,x,y,z,idx=0, h[N],el[M],ne[M],w[M],dist[N],cnt[N];
bool st[N];
queue<int> q;

void add(int x, int y, int z){
    el[idx] = y, w[idx] = z ,ne[idx] = h[x], h[x] = idx ++;
}

bool spfa(){
    for(int i = 1; i<=n; i++){
        q.push(i);
        st[i] = true;
    }
    while(q.size()){
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t];i!=-1;i=ne[i]){
            int j = el[i];
            if(dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >=n) return true;
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}

int main(){
    memset(h, -1, sizeof h);
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i < m; i++){
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
    }
    if(spfa()) puts("Yes");
    else puts("No");
}