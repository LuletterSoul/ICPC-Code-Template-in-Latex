#include<iostream>
using namespace std;


const int N = 1010, M = 1010;
// int n,m, f[N][M], v[N], w[N];
int n,m, f[M], v[N], w[N];

int main(){
    cin >> n >> m;
    for(int i = 1 ; i<= n ; i++) cin >> v[i] >> w[i];
    
    for(int i = 1; i<=n ; i++)
        for(int j = v[i]; j <=m; j++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    
    // for(int i = 1; i <= n; i++)
    //     for(int j = 0; j <= m; j++)
    //         for(int k = 0; k * v[i] <= j; k++){
    //             f[i][j] = max(f[i][j], f[i-1][j - k*v[i]] + k * w[i]);
    // }
    
    cout << f[m] <<endl;
}