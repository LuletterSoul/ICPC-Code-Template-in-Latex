#include<iostream>
using namespace std;

#define N 1010

int a[N][N];
int S[N][N];

int n,m,q,x1,x2,y1,y2;

int main(){
    scanf("%d %d %d",&n,&m, &q);
    for(int i = 1; i<=n;i++)
        for(int j=1; j<=m; j++)
           scanf("%d", &a[i][j]);
    
    for(int i = 1;i<=n;i++)
        for(int j = 1; j<=m;j++)
            S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + a[i][j];
            
            
    while(q--){
        scanf("%d %d %d %d", &x1,&y1, &x2, &y2);
        printf("%d\n", S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1]);
    }
    return 0;
}