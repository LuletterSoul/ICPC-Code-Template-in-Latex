#include<iostream>
using namespace std;

const int N = 20;
typedef long long LL;
int p[N];
int main(){
    int n, m;
    scanf("%d%d",&n,&m);
    int res = 0;
    for(int i = 0 ; i < m; i++) scanf("%d", &p[i]);
    for(int i = 1 ; i < 1 << m; i++){
        int t = 1, cnt = 0;
        for(int j = 0 ; j < m; j++){
            if(i >> j & 1){
                if((LL)t * p[j] > n){
                    t = -1;
                    break;
                }
                cnt++;
                t *= p[j];
            }
        }
        if(t != -1){
            if(cnt % 2) res += n / t;
            else res -= n / t;
        }
    }
    printf("%d\n", res);
    return 0;
}