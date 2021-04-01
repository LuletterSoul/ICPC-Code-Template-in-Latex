/*
f[i][j] = f[i-1][j] + f[i-1][j-i] + f[i-1][j-2*i] + ... f[i-1][j-s * i];
f[i][j-i] =           f[i-1][j-i] + f[i-1][j-2*i] + ... f[i-1][j - s * i];
f[i][j] = f[i-1][j] + f[i][j-i];
*/
#include<iostream>
using namespace std;
const int N = 1010, mod = 1e9 + 7;
int n, f[N];
int main(){
    scanf("%d", &n);
    f[0] = 1;
    for(int i = 1; i <=n ; i++)
        for(int j = i; j <=n; j++) 
            f[j] = (f[j] + f[j - i]) % mod;
    printf("%d\n", f[n]);
    return 0;
}