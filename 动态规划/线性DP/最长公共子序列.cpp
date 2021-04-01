#include<iostream>
using namespace std;


const int N = 1010, M = 1010;

char a[N], b[M];
int n,m,f[N][M];

int main(){
    scanf("%d%d", &n, &m);
    scanf("%s%s", a + 1, b + 1);
    
    for(int i = 1; i <= n ;i ++)
        for(int j =1 ; j <=m ;j ++){
            f[i][j] = max(f[i-1][j], f[i][j-1]);
            if(a[i] == b[j])
                f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
        }
    cout << f[n][m] <<endl;
}