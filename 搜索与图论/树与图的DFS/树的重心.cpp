#include <iostream>
#include <string.h>
using namespace std;

const int N = 100010, M = 2 * N; // 无向图边数比有向图边数多两倍；

int h[N], el[M], ne[M], idx = 0, n,x,y;
int ans = N; 
bool st[N];


void insert(int x ,int y){
    el[idx] = y, ne[idx] = h[x], h[x] = idx ++; //头插法
}

// 计算以u为根节点的树的节点数（包括u自身）
int dfs(int u){
    st[u] = true;    
    int sum = 1, res = 0; // 当前树的节点数，连通子图的节点数最大值；
    for(int i = h[u]; i != -1; i = ne[i]){
        if(!st[el[i]]){
            int s = dfs(el[i]);
            sum += s;
            res = max(res, s);
        }
    }
    
    res = max(res, n - sum); // 比较剩余父连通图的节点数
    ans = min(ans, res);
    return sum;
}


int main(){
    scanf("%d", &n);
    memset(h,-1,sizeof(h));
    for(int i = 0 ; i < n-1 ;i++){// n-1条边，题意
        scanf("%d%d",&x,&y);
        insert(x,y);
        insert(y,x);// 无向图插两条边
    }
    dfs(1);
    printf("%d", ans);
}