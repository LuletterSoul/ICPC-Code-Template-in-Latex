#include<iostream>
using namespace std;
const int N = 110, M = 110;
int n,m,f[M],w[N],v[N],s[N];

int main(){
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> s[i];
        for(int j = 1; j <=s[i]; j++) cin >> v[j] >> w[j];
        for(int j = m; j >=0; j--)
            for(int k = 1; k <= s[i]; k++)
                if(j >= v[k])
                    f[j] = max(f[j], f[j - v[k]] + w[k]);
    }
    
    cout << f[m] << endl;
    return 0;
}