#include <iostream>
using namespace std;

const int N = 20;

char q[N][N];
bool dg[N],udg[N],col[N];
int n;

void dfs(int u ){
    if( u == n){
        for(int i = 0 ; i < n; i++) puts(q[i]);
        puts("");
    }
    
    for(int i = 0 ; i < n; i ++){
        if(!col[i] && !dg[u+i] && !udg[n-u+i]){
            q[u][i] = 'Q'; 
            col[i] = dg[u+i] = udg[n-u+i] = true; // 用截距表示对角线与反对角线
            dfs(u+1);
            col[i] = dg[u+i] = udg[n-u+i] = false;
            q[u][i] = '.'; 
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i = 0 ;i<n;i++)
        for(int j = 0; j< n; j++)
            q[i][j] = '.';
    dfs(0);
}