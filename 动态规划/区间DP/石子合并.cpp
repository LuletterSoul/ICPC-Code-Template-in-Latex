#include<iostream>
using namespace std;

const int N = 310;
int n, m, f[N][N], s[N];

int main(){
    cin >> n;
    for(int i = 1 ; i<=n; i++) cin >> s[i];
    for(int i = 1; i <=n ; i++) s[i] += s[i-1];
    for(int len = 2; len <= n; len ++){
       for(int l = 1; l + len - 1 <= n; l++){
           int r = l + len -1;
           f[l][r] = 1e9;
           for(int k = l; k < r; k++)
                f[l][r] = min(f[l][r], f[l][k] + f[k+1][r] + s[r] - s[l-1]);
       } 
    }
    cout << f[1][n] << endl;
    return 0;
}