#include<iostream>
using namespace std;

const int N = 10010, M = 2010;

int n,m,cnt=0,f[M], v[N], w[N];

int main(){
    cin >> n >> m;
    for(int i = 1 ; i <=n; i++){
        int a,b,s;
        cin >> a >> b >> s;
        int k = 1;
        while(k <= s){
            v[++cnt] = k * a;
            w[cnt] = k * b;
            s -= k;
            k *=2;
        }        
        if(s > 0){
            v[++cnt] = s * a;
            w[cnt] = s * b;
        }
    }
    
    for(int i = 1; i <= cnt; i ++)
        for(int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    
    cout << f[m] <<endl;
    return 0;
}