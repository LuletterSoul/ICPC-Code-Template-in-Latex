#include<iostream>
using namespace std;
const int N = 2010, mod = 1e9 + 7;

int C[N][N], n;

void solve(){
    for(int a = 0 ; a < N; a ++)
        for(int b = 0 ; b <= a ; b++){
            if(!b) C[a][b] = 1;
            else{
                C[a][b] = (C[a-1][b] + C[a-1][b-1]) % mod;
            }
        }
}

int main(){
    cin >> n;
    int a, b;
    solve();
    while(n--){
        cin >> a >> b;
        cout << C[a][b] <<endl;
    }
    return 0;
}