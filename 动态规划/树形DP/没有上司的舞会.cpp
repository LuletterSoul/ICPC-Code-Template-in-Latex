#include<iostream>
#include<cstring>
using namespace std;
const int N = 6010;
int dp[N][2], happy[N], el[N], ne[N], h[N], idx = 0, n;
bool has_father[N];

void insert(int x, int y){
    el[idx] = y, ne[idx] = h[x], h[x] = idx ++;    
}

int dfs(int u){
    dp[u][1] = happy[u]; // 初始化，只选u的快乐值
    for(int i = h[u]; i!=-1; i = ne[i]){
        int j = el[i];
        dfs(j);
        dp[u][0] += max(dp[j][0], dp[j][1]);
        dp[u][1] += dp[j][0];
    }
    return max(dp[u][0], dp[u][1]);
}

int main(){
    memset(h, -1, sizeof h);
    scanf("%d", &n);
    for(int i = 1; i <=n ;i ++) scanf("%d", &happy[i]);
    for(int i = 0; i < n-1; i++){
        int l,k;
        scanf("%d%d", &l, &k);
        insert(k, l); // k是l的祖先，符合头插法
        has_father[l] = true;
    }
    int root =1 ;
    while(has_father[root]) root++;
    printf("%d\n", dfs(root));
    return 0;
}