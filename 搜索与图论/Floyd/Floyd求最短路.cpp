#include <iostream>
#include <string.h>
using namespace std;

const int N = 210, M = 20010, INF = 0x3f3f3f3f;
int n, m, k, d[N][N], x, y, z;


void floyd(){
    for(int k = 1;k <= n; k++)
        for(int i = 1; i <= n; i++) 
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
}


int main(){
    scanf("%d%d%d",&n,&m,&k);
    
    for(int i = 1; i<=n ;i ++)
        for(int j = 1; j <= n; j++){
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    
    for(int i = 0; i < m ;i++){
        scanf("%d%d%d",&x, &y, &z);
        d[x][y] = min(d[x][y], z);
    }
    
    floyd();
    
    while(k -- ){
        scanf("%d%d",&x, &y);
        if(d[x][y] > INF / 2) puts("impossible");
        else printf("%d\n", d[x][y]);
    }
    return 0;
    
}