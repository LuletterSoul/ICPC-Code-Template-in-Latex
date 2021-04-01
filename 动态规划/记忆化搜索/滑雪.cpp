#include<iostream>
#include<cstring>
using namespace std;
const int N = 310, M=310;
int h[N][M], f[N][M], n, m;
int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};

int dfs(int x, int y){
    int &v = f[x][y];
    if(v != -1) return v;
    v = 1;
    for(int i=0; i < 4; i++){
        int a = x + dx[i], b = y + dy[i];
        if(a<=n && a >= 1 && b <=m && b >=1 && h[x][y] > h[a][b])
            v = max(v, dfs(a,b) + 1);
    }
    return v;
}

int main(){
    memset(f, -1, sizeof f);    
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <=m; j++)
            scanf("%d", &h[i][j]);
            
    int res = 0;
    for(int i = 1; i <=n; i++)
        for(int j = 1; j<=m; j++)
            res = max(res, dfs(i,j));
    printf("%d\n", res);
}