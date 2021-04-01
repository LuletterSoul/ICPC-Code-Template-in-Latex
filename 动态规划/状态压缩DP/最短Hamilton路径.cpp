#include<iostream>
#include<cstring>
using namespace std;
const int N = 21, M = 1 << N;
int dp[M][N], a[N][N], n;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = 0;
    for(int i= 0; i < 1 << n; i++)
        for(int j = 0; j < n; j++)
            if(i >> j & 1){
                for(int k = 0; k < n; k ++)
                    if(i ^ 1 << j >> k & 1){
                        dp[i][j] = min(dp[i][j], dp[i ^ 1 << j][k] + a[k][j]);
                    }
            }
    printf("%d\n", dp[(1 << n) - 1][n-1]);
    return 0;
}