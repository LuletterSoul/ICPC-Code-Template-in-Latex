#include <iostream>
#include <string.h>
using namespace std;

typedef pair<int,int> PII;
const int N = 110;

int n,m,h=0,t=-1,d[N][N],g[N][N],dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
PII q[N*N];

int bfs(PII u){
   memset(d,-1,sizeof(d));
   d[u.first][u.second] = 0;
   q[++t] = u;
   while(h<=t){
        auto e = q[h++];
        for(int i = 0 ;i < 4;i++){
            int x = e.first + dx[i], y = e.second + dy[i];
            if(x <= n && x >=1 && y<=m && y>=1 && d[x][y] == -1 && !g[x][y]){
                d[x][y] = d[e.first][e.second] + 1;
                q[++t] = {x,y};
            }
        }
   }
   return d[n][m];
}


int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1 ;i <= n ; i++)
        for(int j = 1; j<= m; j++)
            scanf("%d",&g[i][j]);
    
    printf("%d",bfs({1,1}));
}